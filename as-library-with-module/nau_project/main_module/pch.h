#pragma once

#ifdef _WIN32
    #include "nau/platform/windows/windows_headers.h"
#endif

#include <atomic>
#include <chrono>
#include <cmath>
#include <forward_list>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <optional>
#include <random>
#include <regex>
#include <string>
#include <string_view>
#include <thread>
#include <type_traits>
#include <vector>

#ifdef Yield
    #undef Yield
#endif

#include "nau/diag/assertion.h"
#include "nau/diag/logging.h"
#include "nau/service/service_provider.h"
