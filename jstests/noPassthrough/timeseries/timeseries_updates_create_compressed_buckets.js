/**
 * Tests that an update on a time-series collection keeps the buckets compressed on disk when the
 * feature flag TimeseriesAlwaysUseCompressedBuckets is enabled.
 *
 * @tags: [
 *   requires_timeseries,
 *   featureFlagTimeseriesAlwaysUseCompressedBuckets,
 * ]
 */

import {TimeseriesTest} from "jstests/core/timeseries/libs/timeseries.js";

jsTestLog("Running " + jsTestName());

const conn = MongoRunner.runMongod({});
const db = conn.getDB("test");

const timeField = "time";
const kBucketMax = 1000;

// Create the time-series collection.
assert.commandWorked(db.createCollection(jsTestName(), {timeseries: {timeField: timeField}}));
const coll = db.getCollection(jsTestName());
const bucketsColl = db.getCollection("system.buckets." + jsTestName());

function insertAndCheckBuckets(value) {
    assert.commandWorked(coll.insert({[timeField]: ISODate(), x: value}));
    let buckets = bucketsColl.find().toArray();
    buckets.forEach((bucket, index) => {
        assert.eq(
            bucket.control.version,
            TimeseriesTest.BucketVersion.kCompressed,
            `Bucket ${index} does not have the correct version. Expected ${
                TimeseriesTest.BucketVersion.kCompressed}, but got ${bucket.control.version}`);
    });
}

// The first insert and 1 - kBucketMax subsequent updates should all go to the same compressed
// bucket.
for (let i = 0; i < kBucketMax; i++) {
    insertAndCheckBuckets(i);
}

let buckets = bucketsColl.find().toArray();
assert.eq(buckets.length, 1, `Expected 1 bucket, but got ${buckets.length}: ${tojson(buckets)}`);

// Compression statistics are only updated when a bucket is closed.
let stats = assert.commandWorked(coll.stats());
assert.eq(0, stats.timeseries['numBytesUncompressed']);
assert.eq(0, stats.timeseries['numBytesCompressed']);

// The full bucket should be closed and a future measurement should go to another bucket.
insertAndCheckBuckets(kBucketMax);
buckets = bucketsColl.find().toArray();
assert.eq(buckets.length, 2, `Expected 2 buckets, but got ${buckets.length}: ${tojson(buckets)}`);

// First bucket is now closed, we should have some compression metrics.
stats = assert.commandWorked(coll.stats());
assert.gt(stats.timeseries['numBytesUncompressed'], 0);
assert.gt(stats.timeseries['numBytesCompressed'], 0);

MongoRunner.stopMongod(conn);