cmake_minimum_required(VERSION 3.12)

project(cpp_template)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(USE_UBSAN "Enable Undefined Behavior Sanitizer" OFF)
option(USE_ASAN "Enable Address Sanitizer" OFF)
option(USE_TSAN "Enable Thread Sanitizer" OFF)

include(cmake/Sanitizers.cmake)
include(cmake/GTest.cmake)
include(cmake/CustomTargets.cmake)

find_package(SDL2 REQUIRED)

add_subdirectory(3party/fmt)
add_subdirectory(3party/tl)
add_subdirectory(3party/json)
add_subdirectory(3party/imgui-1.90.5)

add_subdirectory(lib)
add_subdirectory(cmd)
add_subdirectory(test)
