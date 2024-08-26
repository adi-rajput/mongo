/**
 *    Copyright (C) 2024-present MongoDB, Inc.
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

#include "mongo/db/query/ce/test_utils.h"
#include <map>
#include <memory>
#include <ostream>
#include <random>
#include <tuple>
#include <utility>
#include <vector>

#include "mongo/bson/bsonobj.h"
#include "mongo/db/query/ce/cbp_histogram_ce/test_helpers.h"
#include "mongo/db/query/stats/max_diff.h"
#include "mongo/unittest/assert.h"
#include "mongo/unittest/framework.h"

#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kDefault

using namespace mongo::optimizer::cbp::ce;
using namespace mongo;

namespace value = sbe::value;

using stats::TypeCounts;
using TypeTags = value::TypeTags;
using TypeProbability = std::pair<value::TypeTags, size_t>;
using TypeCombination = std::vector<TypeProbability>;
using TypeCombinations = std::vector<TypeCombination>;

bool checkTypeExistence(const TypeProbability& typeCombinationQuery,
                        const TypeCombination& typeCombinationsData) {

    bool typeExists = false;
    for (const auto& typeCombinationData : typeCombinationsData) {
        if (typeCombinationQuery.first == typeCombinationData.first) {
            typeExists = true;
        }
    }

    return typeExists;
}

void runAccuracyTestConfiguration(const DataDistributionEnum dataDistribution,
                                  const TypeCombinations& typeCombinationsData,
                                  const TypeCombination& typeCombinationsQueries,
                                  const std::vector<int>& numberOfBucketsVector,
                                  const size_t size,
                                  const std::pair<size_t, size_t>& dataInterval,
                                  const std::pair<size_t, size_t>& queryInterval,
                                  const int numberOfQueries,
                                  QueryType queryType,
                                  const size_t seed,
                                  bool printResults) {


    for (auto numberOfBuckets : numberOfBucketsVector) {
        for (const auto& typeCombinationData : typeCombinationsData) {
            // Random value generator for actual data in histogram.
            std::vector<stats::SBEValue> data;
            std::map<stats::SBEValue, double> insertedData;

            // Create one by one the values.
            switch (dataDistribution) {
                case kUniform:
                    generateDataUniform(size, dataInterval, typeCombinationData, seed, data);
                    break;
                case kNormal:
                    generateDataNormal(size, dataInterval, typeCombinationData, seed, data);
                    break;
                case kZipfian:
                    generateDataZipfian(size, dataInterval, typeCombinationData, seed, data);
                    break;
            }

            // Build histogram.
            auto arrHist = stats::createArrayEstimator(data, numberOfBuckets);

            // Run queries.
            for (const auto& typeCombinationQuery : typeCombinationsQueries) {

                if (!checkTypeExistence(typeCombinationQuery, typeCombinationData)) {
                    continue;
                }

                auto error = runQueries(size,
                                        numberOfQueries,
                                        queryType,
                                        queryInterval,
                                        typeCombinationQuery,
                                        data,
                                        arrHist,
                                        true /*includeScalar*/,
                                        seed);
                if (printResults) {
                    printResult(dataDistribution,
                                typeCombinationData,
                                size,
                                numberOfBuckets,
                                typeCombinationQuery,
                                numberOfQueries,
                                queryType,
                                dataInterval,
                                error);
                }
            }
        }
    }
}

/**
 * This program generates accuracy calculations for histogram frequency estimates.
 * The program creates varying distribution datasets (Uniform, Normal, Zipfian), populates a
 * histogram with varying number of buckets, and executes a sequence of point and range queries.
 * The program compares the estimated output with the correct results and outputs the error stats.
 * The collected stats are outputed in CSV format as part of the mongodb log.
 */
int main(int argc, char* argv[]) {

    // the TypeCombination pair defines the probability of this specific type appearing in the
    // dataset
    const TypeCombinations typeCombinationsData{
        TypeCombination{{TypeTags::NumberInt64, 100}},
        TypeCombination{{TypeTags::StringSmall, 100}},
        TypeCombination{{TypeTags::NumberDouble, 100}},
        TypeCombination{{TypeTags::Array, 100}},
        TypeCombination{{TypeTags::NumberInt64, 30}, {TypeTags::StringSmall, 70}},
        TypeCombination{
            {TypeTags::NumberInt64, 40}, {TypeTags::StringSmall, 30}, {TypeTags::NumberDouble, 30}},
        TypeCombination{
            {TypeTags::NumberInt64, 30}, {TypeTags::NumberDouble, 40}, {TypeTags::Array, 30}}};

    const std::vector<int> numberOfBuckets{10, 50, 100, 200};
    const size_t size = 50000;
    const int numberOfQueries = 1000;
    bool printResults = true;
    const size_t seed = 1724178214;

    if (printResults) {
        printHeader();
    }

    // Point queries

    {
        const TypeCombination typeCombinationsQueries{{TypeTags::NumberInt64, 100},
                                                      {TypeTags::StringSmall, 100},
                                                      {TypeTags::NumberDouble, 100}};

        const std::pair<size_t, size_t> dataInterval({0, 1000});
        const std::pair<size_t, size_t> queryInterval({0, 1000});
        const DataDistributionEnum dataDistribution = kUniform;
        QueryType queryType = kPoint;

        runAccuracyTestConfiguration(dataDistribution,
                                     typeCombinationsData,
                                     typeCombinationsQueries,
                                     numberOfBuckets,
                                     size,
                                     dataInterval,
                                     queryInterval,
                                     numberOfQueries,
                                     queryType,
                                     seed,
                                     printResults);
    }

    {
        const TypeCombination typeCombinationsQueries{{TypeTags::NumberInt64, 100},
                                                      {TypeTags::StringSmall, 100},
                                                      {TypeTags::NumberDouble, 100}};
        const std::pair<size_t, size_t> dataInterval({500, 150});
        const std::pair<size_t, size_t> queryInterval({0, 1000});
        const DataDistributionEnum dataDistribution = kNormal;
        QueryType queryType = kPoint;

        runAccuracyTestConfiguration(dataDistribution,
                                     typeCombinationsData,
                                     typeCombinationsQueries,
                                     numberOfBuckets,
                                     size,
                                     dataInterval,
                                     queryInterval,
                                     numberOfQueries,
                                     queryType,
                                     seed,
                                     printResults);
    }

    {
        const TypeCombination typeCombinationsQueries{{TypeTags::NumberInt64, 100},
                                                      {TypeTags::StringSmall, 100},
                                                      {TypeTags::NumberDouble, 100}};
        const std::pair<size_t, size_t> dataInterval({0, 1000});
        const std::pair<size_t, size_t> queryInterval({0, 1000});
        const DataDistributionEnum dataDistribution = kZipfian;
        QueryType queryType = kPoint;

        runAccuracyTestConfiguration(dataDistribution,
                                     typeCombinationsData,
                                     typeCombinationsQueries,
                                     numberOfBuckets,
                                     size,
                                     dataInterval,
                                     queryInterval,
                                     numberOfQueries,
                                     queryType,
                                     seed,
                                     printResults);
    }

    // Range queries

    {
        const TypeCombination typeCombinationsQueries{{TypeTags::NumberInt64, 100},
                                                      {TypeTags::NumberDouble, 100}};
        const std::pair<size_t, size_t> dataInterval({0, 1000});
        const std::pair<size_t, size_t> queryInterval({0, 1000});
        const DataDistributionEnum dataDistribution = kUniform;
        QueryType queryType = kRange;

        runAccuracyTestConfiguration(dataDistribution,
                                     typeCombinationsData,
                                     typeCombinationsQueries,
                                     numberOfBuckets,
                                     size,
                                     dataInterval,
                                     queryInterval,
                                     numberOfQueries,
                                     queryType,
                                     seed,
                                     printResults);
    }

    {
        const TypeCombination typeCombinationsQueries{{TypeTags::NumberInt64, 100},
                                                      {TypeTags::NumberDouble, 100}};
        const std::pair<size_t, size_t> dataInterval({0, 1000});
        const std::pair<size_t, size_t> queryInterval({0, 1000});
        const DataDistributionEnum dataDistribution = kNormal;
        QueryType queryType = kRange;

        runAccuracyTestConfiguration(dataDistribution,
                                     typeCombinationsData,
                                     typeCombinationsQueries,
                                     numberOfBuckets,
                                     size,
                                     dataInterval,
                                     queryInterval,
                                     numberOfQueries,
                                     queryType,
                                     seed,
                                     printResults);
    }

    {
        const TypeCombination typeCombinationsQueries{{TypeTags::NumberInt64, 100},
                                                      {TypeTags::NumberDouble, 100}};
        const std::pair<size_t, size_t> dataInterval({0, 1000});
        const std::pair<size_t, size_t> queryInterval({0, 1000});
        const DataDistributionEnum dataDistribution = kZipfian;
        QueryType queryType = kRange;

        runAccuracyTestConfiguration(dataDistribution,
                                     typeCombinationsData,
                                     typeCombinationsQueries,
                                     numberOfBuckets,
                                     size,
                                     dataInterval,
                                     queryInterval,
                                     numberOfQueries,
                                     queryType,
                                     seed,
                                     printResults);
    }
}
