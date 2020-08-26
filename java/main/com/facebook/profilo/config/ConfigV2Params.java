/**
 * Copyright 2004-present, Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the
 * License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.facebook.profilo.config;

import com.facebook.proguard.annotations.DoNotStripAny;
import java.util.TreeMap;
import javax.annotation.Nullable;

@DoNotStripAny
public class ConfigV2Params {
  static final ConfigV2Params EMPTY = new ConfigV2Params();

  @Nullable public TreeMap<String, Integer> intParams;
  @Nullable public TreeMap<String, Boolean> boolParams;
  @Nullable public TreeMap<String, int[]> intListParams;
  @Nullable public TreeMap<String, String> stringParams;
  @Nullable public TreeMap<String, String[]> stringListParams;
}
