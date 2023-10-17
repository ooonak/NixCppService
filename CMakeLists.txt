cmake_minimum_required(VERSION 3.26)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source!")
endif()

project(CppService LANGUAGES CXX)

include(CTest)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(BUILD_TESTING "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

set(TARGET_SPECIFIC_OPTIONS -Werror)
set(TARGET_SPECIFIC_OPTIONS ${TARGET_SPECIFIC_OPTIONS} -Wall -Wextra -Wpedantic)
set(TARGET_SPECIFIC_OPTIONS ${TARGET_SPECIFIC_OPTIONS} -Wnull-dereference -Wshadow -Wunused -Wnon-virtual-dtor -Woverloaded-virtual)
set(TARGET_SPECIFIC_OPTIONS ${TARGET_SPECIFIC_OPTIONS} -Wold-style-cast -Wcast-qual -Wcast-align -Wsign-conversion)
#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    set(TARGET_SPECIFIC_OPTIONS ${TARGET_SPECIFIC_OPTIONS} -stdlib=libc++)
#endif()
set(TARGET_SPECIFIC_DEBUG_OPTIONS ${TARGET_SPECIFIC_OPTIONS} -g -O1)
set(TARGET_SPECIFIC_RELEASE_OPTIONS ${TARGET_SPECIFIC_OPTIONS} -O3)

if (DEFINED CMAKE_BUILD_TYPE)
    if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
        message(STATUS "TARGET_SPECIFIC_RELEASE_OPTIONS: ${TARGET_SPECIFIC_RELEASE_OPTIONS}")
    elseif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
        message(STATUS "TARGET_SPECIFIC_DEBUG_OPTIONS: ${TARGET_SPECIFIC_DEBUG_OPTIONS}")
    else()
        message(STATUS "No specific options set, neither Debug or Release build (${CMAKE_BUILD_TYPE})?")
    endif()
endif()

find_package(spdlog REQUIRED)

add_subdirectory(src)

if(BUILD_EXAMPLES)
    add_subdirectory(example)
endif(BUILD_EXAMPLES)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif(BUILD_TESTING)
