/*
 * Copyright (C) 2024 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>

namespace android {
namespace hardware {
namespace google {
namespace pixel {

namespace mm_metrics_reporter_test_golden_result {
/**
 * Per hour data are snapshot data, mostly (except for PSI) are
 * directly from corresponding sysnode values.  field mapping could be
 * obtained in the atom (i.e. PixelMmMetricsPerHour) definition.
 * the field name also suggests the related sysfs node and fields.
 *
 * Test values (i.e. data injection for sysfs nodes) are first
 * generated by a script, and then manually modified and examined, to
 * ensure each field has unique value (to catch erroneous writes to
 * the wrong entries (wrong offsets).
 */
const int64_t PixelMmMetricsPerHour_golden[]{
        // clang-format off
    2645,
    2761,
    2769,
    2713,
    2685,
    2709,
    3225,
    3229,
    2717,
    7048,
    9050,
    8049,
    11052,
    10051,
    220,
    720,
    470,
    250,
    750,
    500,
    280,
    780,
    530,
    420,
    920,
    670,
    450,
    950,
    700,
    480,
    980,
    730,
    320,
    820,
    570,
    350,
    850,
    600,
    380,
    880,
    630,
    620,
    1120,
    870,
    650,
    1150,
    900,
    680,
    1180,
    930,
    520,
    1020,
    770,
    550,
    1050,
    800,
    580,
    1080,
    830,
    -1,
    2785,
    2677,
    177,
        // clang-format on
};

/**
 * Per day data are diff data from previous day read of related sysfs
 * nodes..
 *
 * Test values (i.e. data injection for sysfs nodes) are first
 * generated by a script, and then manually modified and examined, to
 * ensure each field has unique value (to catch erroneous writes to
 * the wrong entries (wrong offsets).
 */
const int64_t PixelMmMetricsPerDay_golden[]{
        // clang-format off
    1297761,
    1026845,
    1029713,
    1291325,
    1041225,
    1044113,
    1047005,
    1294541,
    1032585,
    1035461,
    1038341,
    1084965,
    1087913,
    1090865,
    1093821,
    1138641,
    1412981,
    1419713,
    1416345,
    181,
    53,
    1336713,
    1339985,
    1343261,
    1346541,
    1349825,
    1396221,
    1399565,
    1402913,
    1406265,
    1409621,
    1376241,
    1379561,
    1382885,
    1386213,
    1389545,
    1356405,
    1359701,
    1363001,
    1366305,
    1369613,
    1313921,
    1317165,
    1320413,
    1323665,
    1326921,
    1330181,
    937181,
    939921,
    1172081,
    1169021,
    1120605,
    1123601,
    1227845,
    1253045,
    1240413,
    1153781,
    1246721,
    -1,
    55250,
    5201,
    5405,
    1126601,
        // clang-format on
};
}  // namespace mm_metrics_reporter_test_golden_result

}  // namespace pixel
}  // namespace google
}  // namespace hardware
}  // namespace android
