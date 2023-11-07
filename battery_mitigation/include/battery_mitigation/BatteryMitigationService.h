/*
 * Copyright (C) 2023 The Android Open Source Project
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

#pragma once

#include <algorithm>
#include <cmath>
#include <errno.h>
#include <unistd.h>
#include <thread>
#include <sys/eventfd.h>
#include <sys/epoll.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/system_properties.h>
#include <utils/RefBase.h>
#include <android-base/chrono_utils.h>
#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/parseint.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "MitigationConfig.h"
#include "uapi/brownout_stats.h"

#define MIN_SUPPORTED_PLATFORM   2 /* CDT */
#define MAX_SUPPORTED_PLATFORM   5
#define NSEC_PER_SEC             1000000000L
#define BROWNOUT_EVENT_BUF_SIZE  10
#define DUMP_TIMES               12
#define EPOLL_MAXEVENTS          5
#define BUF_SIZE                 128
#define FVP_STATS_SIZE           4096
#define UP_DOWN_LINK_SIZE        512
#define STAT_NAME_SIZE           48
#define STATS_MAX_SIZE           64
#define PMIC_NUM                 2

namespace android {
namespace hardware {
namespace google {
namespace pixel {

using ::android::sp;
using android::hardware::google::pixel::MitigationConfig;

struct numericStat {
    char name[STAT_NAME_SIZE];
    int value;
};

struct OdpmInstantPower {
    struct timespec time;
    double value;
};

struct BrownoutStatsExtend {
    struct brownout_stats brownoutStats;
    char fvpStats[FVP_STATS_SIZE];
    char pcieModem[UP_DOWN_LINK_SIZE];
    char pcieWifi[UP_DOWN_LINK_SIZE];
    struct numericStat numericStats[STATS_MAX_SIZE];
    timeval eventReceivedTime;
    timeval dumpTime;
    unsigned int eventIdx;
};

class BatteryMitigationService : public RefBase {
  public:
    BatteryMitigationService(const struct MitigationConfig::EventThreadConfig &eventThreadCfg,
                             int platformNum);
    ~BatteryMitigationService();

    void startBrownoutEventThread();
    void stopBrownoutEventThread();
    bool isBrownoutStatsBinarySupported();
    bool isPlatformSupported();
    bool isTimeValid(const char*, std::chrono::system_clock::time_point);
    bool genParsedMeal(const char*);
  private:
    struct MitigationConfig::EventThreadConfig cfg;
    int platformNum;
    int platformIdx;
    int brownoutStatsFd;
    int triggeredIdxFd;
    int triggeredIdxEpollFd;
    int wakeupEventFd;
    char *storingAddr;
    std::vector<MitigationConfig::numericSysfs> totalNumericSysfsStatPaths;
    std::atomic_bool threadStop{false};
    std::thread brownoutEventThread;

    void BrownoutEventThread();
    void initTotalNumericSysfsPaths();
    int initThisMeal();
    int initFd();
    void tearDownBrownoutEventThread();
    int readNumericStats(struct BrownoutStatsExtend*);
    bool parseBrownoutStatsExtend(FILE *);
    void printBrownoutStatsExtendSummary(FILE *, struct BrownoutStatsExtend *);
};

}  // namespace pixel
}  // namespace google
}  // namespace hardware
}  // namespace android
