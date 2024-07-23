/**
 *    Copyright (C) 2018-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#include <boost/cstdint.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include <boost/move/utility_core.hpp>
#include <boost/optional/optional.hpp>

#include "mongo/base/error_codes.h"
#include "mongo/base/parse_number.h"
#include "mongo/base/status.h"
#include "mongo/base/string_data.h"
#include "mongo/bson/bsonelement.h"
#include "mongo/bson/bsonmisc.h"
#include "mongo/bson/bsonobjbuilder.h"
#include "mongo/bson/bsontypes.h"
#include "mongo/db/basic_types.h"
#include "mongo/db/curop.h"
#include "mongo/db/matcher/expression_parser.h"
#include "mongo/db/pipeline/document_source_replace_root.h"
#include "mongo/db/pipeline/expression_context.h"
#include "mongo/db/pipeline/field_path.h"
#include "mongo/db/query/canonical_distinct.h"
#include "mongo/db/query/collation/collator_factory_interface.h"
#include "mongo/db/query/distinct_command_gen.h"
#include "mongo/db/query/find_command.h"
#include "mongo/db/query/query_request_helper.h"
#include "mongo/db/repl/read_concern_args.h"
#include "mongo/idl/idl_parser.h"
#include "mongo/util/assert_util.h"
#include "mongo/util/intrusive_counter.h"
#include "mongo/util/str.h"

namespace mongo {

const char CanonicalDistinct::kKeyField[] = "key";
const char CanonicalDistinct::kQueryField[] = "query";
const char CanonicalDistinct::kCollationField[] = "collation";
const char CanonicalDistinct::kUnwoundArrayFieldForViewUnwind[] = "_internalUnwoundArray";
const char CanonicalDistinct::kHintField[] = "hint";

namespace {

/**
 * Helper for when converting a distinct() to an aggregation pipeline. This function may add a
 * $match stage enforcing that intermediate subpaths are objects so that no implicit array
 * traversal happens later on. The $match stage is only added when the path is dotted (e.g. "a.b"
 * but for "xyz").
 *
 * See comments in CanonicalDistinct::asAggregationCommand() for more detailed explanation.
 */
void addMatchRemovingNestedArrays(BSONArrayBuilder* pipelineBuilder, const FieldPath& unwindPath) {
    if (unwindPath.getPathLength() == 1) {
        return;
    }
    invariant(unwindPath.getPathLength() > 1);

    BSONObjBuilder matchBuilder(pipelineBuilder->subobjStart());
    BSONObjBuilder predicateBuilder(matchBuilder.subobjStart("$match"));


    for (size_t i = 0; i < unwindPath.getPathLength() - 1; ++i) {
        StringData pathPrefix = unwindPath.getSubpath(i);
        // Add a clause to the $match predicate requiring that intermediate paths are objects so
        // that no implicit array traversal happens.
        predicateBuilder.append(pathPrefix,
                                BSON("$_internalSchemaType"
                                     << "object"));
    }

    predicateBuilder.doneFast();
    matchBuilder.doneFast();
}

}  // namespace

boost::intrusive_ptr<ExpressionContext> CanonicalDistinct::makeExpressionContext(
    OperationContext* opCtx,
    const NamespaceString& nss,
    const DistinctCommandRequest& distinctCommand,
    const CollatorInterface* defaultCollator,
    boost::optional<ExplainOptions::Verbosity> verbosity) {

    std::unique_ptr<CollatorInterface> collator;
    if (auto collationObj = distinctCommand.getCollation().get_value_or(BSONObj());
        !collationObj.isEmpty()) {
        collator = uassertStatusOK(
            CollatorFactoryInterface::get(opCtx->getServiceContext())->makeFromBSON(collationObj));
    } else if (defaultCollator) {
        // The 'collPtr' will be null for views, but we don't need to worry about views here. The
        // views will get rewritten into aggregate command and will regenerate the
        // ExpressionContext.
        collator = defaultCollator->clone();
    }
    auto expCtx =
        make_intrusive<ExpressionContext>(opCtx,
                                          distinctCommand,
                                          nss,
                                          std::move(collator),
                                          CurOp::get(opCtx)->dbProfileLevel() > 0,  // mayDbProfile
                                          verbosity);
    return expCtx;
}

}  // namespace mongo
