/**
 * Copyright 2004-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <fbjni/fbjni.h>
#include <util/ProcFs.h>
#include <util/SysFs.h>
#include <mutex>
#include <unordered_map>
#include <unordered_set>

namespace facebook {
namespace profilo {

class SystemCounterThread
    : public facebook::jni::HybridClass<SystemCounterThread> {
 public:
  constexpr static auto kJavaDescriptor =
      "Lcom/facebook/profilo/provider/systemcounters/SystemCounterThread;";

  static facebook::jni::local_ref<jhybriddata> initHybrid(
      facebook::jni::alias_ref<jclass>);

  static void registerNatives();

  void logCounters();
  void logThreadCounters();
  void logHighFrequencyThreadCounters();
  void logTraceAnnotations();

 private:
  friend HybridBase;
  SystemCounterThread() = default;

  std::mutex mtx_; // Guards cache_
  util::ThreadCache cache_;
  std::unique_ptr<util::TaskStatFile> processStatFile_;
  std::unique_ptr<util::CpuFrequencyStats> cpuFrequencyStats_;
  std::unique_ptr<util::VmStatFile> vmStats_;
  bool vmStatsTracingDisabled_;
  std::unique_ptr<util::TaskSchedFile> schedStats_;
  bool schedStatsTracingDisabled_;
  std::unique_ptr<util::TaskIoFile> ioStats_;
  bool ioStatsTracingDisabled_;
  int32_t extraAvailableCounters_;
  bool highFrequencyMode_;

  void logProcessCounters();
  void logCpuFrequencyInfo();
  void logVmStatCounters();
  void logProcessSchedCounters();
  void logIoStatCounters();
  void setHighFrequencyMode(bool enabled) {
    highFrequencyMode_ = enabled;
  }
};

} // namespace profilo
} // namespace facebook
