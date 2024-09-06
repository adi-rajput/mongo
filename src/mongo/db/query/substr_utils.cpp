/**
 *    Copyright (C) 2023-present MongoDB, Inc.
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

#include <string_view>

#include "mongo/base/error_codes.h"
#include "mongo/db/query/substr_utils.h"
#include "mongo/util/assert_util.h"
#include "mongo/util/str.h"

namespace mongo::substr_utils {

StringData getSubstringCP(StringData input, int startingPos, int len) {
    std::size_t startIndexBytes = 0;
    for (int i = 0; i < startingPos; ++i) {
        if (startIndexBytes >= input.size()) {
            return StringData();
        }
        uassert(34456,
                "$substrCP: invalid UTF-8 string",
                !str::isUTF8ContinuationByte(input[startIndexBytes]));
        std::size_t codePointLength = str::getCodePointLength(input[startIndexBytes]);
        uassert(34457, "$substrCP: invalid UTF-8 string", codePointLength <= 4);
        startIndexBytes += codePointLength;
    }

    std::size_t endIndexBytes = startIndexBytes;
    for (int i = 0; i < len && endIndexBytes < input.size(); ++i) {
        uassert(34458,
                "$substrCP: invalid UTF-8 string",
                !str::isUTF8ContinuationByte(input[endIndexBytes]));
        std::size_t codePointLength = str::getCodePointLength(input[endIndexBytes]);
        uassert(34459, "$substrCP: invalid UTF-8 string", codePointLength <= 4);
        endIndexBytes += codePointLength;
    }
    size_t endPos = endIndexBytes - startIndexBytes;
    return input.substr(startIndexBytes, endPos);
}

}  // namespace mongo::substr_utils
