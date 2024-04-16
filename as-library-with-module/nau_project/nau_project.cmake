cmake_minimum_required (VERSION 3.19)

if (POLICY CMP0091)
  cmake_policy(SET CMP0091 OLD)
endif()


set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(NAU_INCLUDE_ENGINE_MS_PROJECTS ON)

set(CMAKE_CXX_STANDARD 20)


set (NAU_BUILD_DIR "${NAU_ROOT_DIR}/build/${NAU_BUILD_NAME}")

set(CMAKE_MODULE_PATH
  "${NAU_BUILD_DIR}/cmake"
  "${NAU_ROOT_DIR}/cmake"
)


include (NauThirdPartyTargets)
include (NauKernelTargets)
include (NauModulesApiTargets)
include (NauLinkedModulesTargets)

include (NauCoreTargets)

include (NauCommon)
include (NauModule)
include (platformSpec/NauPlatformSetup)


nau_collect_cmake_subdirectories(modules ${CMAKE_CURRENT_LIST_DIR})
foreach(module ${modules})
  message(STATUS "project module: (${module})")
  add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/${module})
endforeach()

if (NAU_INCLUDE_ENGINE_MS_PROJECTS AND MSVC)

  include_external_msproject(
    NauKernel_Import "${NAU_BUILD_DIR}/engine/core/kernel/src/NauKernel.vcxproj"
    GUID  00CC00AA-BBB2-C3CC-87E1-00FF00FF00FF
  )

  include_external_msproject(
    NauFramework_Import "${NAU_BUILD_DIR}/engine/core/app_framework/src/NauFramework.vcxproj"
    GUID  00CC00AA-BBB2-C3CC-87E1-00FF00FF00FF
  )

  set_target_properties (
    NauKernel_Import NauFramework_Import
    PROPERTIES
      FOLDER "Engine"
  )

endif()
