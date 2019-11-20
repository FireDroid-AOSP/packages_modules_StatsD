/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include <android/os/BnPullAtomResultReceiver.h>

using namespace std;

namespace android {
namespace os {
namespace statsd {

class PullResultReceiver : public BnPullAtomResultReceiver {
public:
    PullResultReceiver(function<void(int32_t, bool, const vector<android::util::StatsEvent>&)>
                               pullFinishCallback);
    ~PullResultReceiver();

    /**
     * Binder call for finishing a pull.
     */
    binder::Status pullFinished(int32_t atomTag, bool success,
                                        const vector<android::util::StatsEvent>& output) override;

private:
    function<void(int32_t, bool, const vector<android::util::StatsEvent>&)> pullFinishCallback;
};

}  // namespace statsd
}  // namespace os
}  // namespace android