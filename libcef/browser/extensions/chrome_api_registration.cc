// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// APIs must also be registered in
// libcef/common/extensions/api/_*_features.json files. See
// libcef/common/extensions/api/README.txt for additional details.

#include "libcef/browser/extensions/chrome_api_registration.h"

#include "libcef/browser/extensions/api/tabs/tabs_api.h"

#include "chrome/browser/extensions/api/resources_private/resources_private_api.h"
#include "chrome/browser/extensions/api/streams_private/streams_private_api.h"
#include "extensions/browser/extension_function_registry.h"

namespace extensions {
namespace api {
namespace cef {

namespace cefimpl = extensions::cef;

#define EXTENSION_FUNCTION_NAME(classname) classname::function_name()

// Maintain the same order as https://developer.chrome.com/extensions/api_index
// so chrome://extensions-support looks nice.
const char* const kSupportedAPIs[] = {
    "resourcesPrivate",
    EXTENSION_FUNCTION_NAME(ResourcesPrivateGetStringsFunction),
    "streamsPrivate",
    EXTENSION_FUNCTION_NAME(StreamsPrivateAbortFunction),
    "tabs",
    EXTENSION_FUNCTION_NAME(cefimpl::TabsGetFunction),
    EXTENSION_FUNCTION_NAME(cefimpl::TabsExecuteScriptFunction),
    EXTENSION_FUNCTION_NAME(cefimpl::TabsInsertCSSFunction),
    EXTENSION_FUNCTION_NAME(cefimpl::TabsSetZoomFunction),
    EXTENSION_FUNCTION_NAME(cefimpl::TabsGetZoomFunction),
    EXTENSION_FUNCTION_NAME(cefimpl::TabsSetZoomSettingsFunction),
    EXTENSION_FUNCTION_NAME(cefimpl::TabsGetZoomSettingsFunction),
    nullptr,  // Indicates end of array.
};

// Only add APIs to this list that have been tested in CEF.
// static
bool ChromeFunctionRegistry::IsSupported(const std::string& name) {
  for (size_t i = 0; kSupportedAPIs[i] != nullptr; ++i) {
    if (name == kSupportedAPIs[i])
      return true;
  }
  return false;
}

// Only add APIs to this list that have been tested in CEF.
// static
void ChromeFunctionRegistry::RegisterAll(ExtensionFunctionRegistry* registry) {
  registry->RegisterFunction<ResourcesPrivateGetStringsFunction>();
  registry->RegisterFunction<StreamsPrivateAbortFunction>();
  registry->RegisterFunction<cefimpl::TabsExecuteScriptFunction>();
  registry->RegisterFunction<cefimpl::TabsInsertCSSFunction>();
  registry->RegisterFunction<cefimpl::TabsGetFunction>();
  registry->RegisterFunction<cefimpl::TabsSetZoomFunction>();
  registry->RegisterFunction<cefimpl::TabsGetZoomFunction>();
  registry->RegisterFunction<cefimpl::TabsSetZoomSettingsFunction>();
  registry->RegisterFunction<cefimpl::TabsGetZoomSettingsFunction>();
}

}  // namespace cef
}  // namespace api
}  // namespace extensions
