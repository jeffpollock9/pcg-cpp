cmake_minimum_required(VERSION 3.0.0)

project(rando LANGUAGES CXX VERSION "0.0.1")

option(RANDO_TEST "Enable testing" OFF)
option(RANDO_BENCHMARK "Enable benchmarks" OFF)

message("-- Configuring rando version: ${PROJECT_VERSION}")
message("--   Options:")
message("--     RANDO_TEST: ${RANDO_TEST}")
message("--     RANDO_BENCHMARK: ${RANDO_BENCHMARK}")

add_library(rando INTERFACE)

target_include_directories(rando INTERFACE "${PROJECT_SOURCE_DIR}/include")
target_compile_options(rando INTERFACE "-std=c++14") ## TODO: find better way

if (RANDO_TEST OR RANDO_BENCHMARK)
    add_subdirectory(ext/pcg-cpp)
endif ()

if (RANDO_TEST)
    include(CTest)
    add_subdirectory(ext/googletest)
    add_subdirectory(test)
endif ()

if (RANDO_BENCHMARK)
    option(BENCHMARK_ENABLE_TESTING "Override benchmark library testing" OFF)
    add_subdirectory(ext/benchmark)
    add_subdirectory(benchmark)
endif ()
