cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cpp-sugar VERSION "0.1.0")

# <<< General set up >>>
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

option(ENABLE_UNIT_TESTS "Enable unit tests" ON)

if(CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
    message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
    list(APPEND flags "-Wextra" "-Wpedantic")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_library(${PROJECT_NAME} SHARED "")

target_sources(${PROJECT_NAME}
        PRIVATE
        src/string.cpp
        src/json.cpp
        include/csugar.h)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Boost REQUIRED)
find_package(jsoncpp REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        jsoncpp)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        POSITION_INDEPENDENT_CODE 1
        SOVERSION ${PROJECT_VERSION_MAJOR}
        OUTPUT_NAME "csugar"
        DEBUG_POSTFIX "_d"
        PUBLIC_HEADER "csugar.h"
        MACOSX_RPATH ON
        WINDOWS_EXPORT_ALL_SYMBOLS ON)

#find_package(boost REQUIRED)

add_subdirectory(external)

message(STATUS "Enable testing")
include(CTest)
enable_testing()
add_executable(tests
        tests/main.cpp)
target_link_libraries(tests
        PRIVATE
        ${PROJECT_NAME}
        jsoncpp
        gtest_main
        gmock_main)
add_test(NAME google_test
        COMMAND $<TARGET_FILE:tests>)
