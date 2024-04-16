#pragma once

#ifdef _WIN32
    #include "nau/platform/windows/windows_headers.h"
#endif

#include <EASTL/string.h>
#include <EASTL/vector.h>

#include <atomic>
#include <iostream>

#ifdef Yield
    #undef Yield
#endif

#include "nau/rtti/ptr.h"
#include "nau/service/service_provider.h"
#include "nau/utils/scope_guard.h"
