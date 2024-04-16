cmake_minimum_required (VERSION 3.19)
project (AppSample_2)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



include(nau_project/nau_project.cmake)


nau_collect_files(Sources
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/src
  MASK "*.cpp" "*.h"
)

add_executable(MyProject ${Sources})

target_precompile_headers(MyProject PRIVATE src/pch.h)
target_include_directories(MyProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(MyProject PRIVATE
  MainGameModule
)



source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${Sources})
nau_add_compile_options(MyProject)
nau_target_link_public_modules(MyProject)
