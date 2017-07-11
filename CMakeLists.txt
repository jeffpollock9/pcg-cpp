cmake_minimum_required(VERSION 3.0.0)

project(rando LANGUAGES CXX VERSION "0.0.1")

option(RANDO_TEST "Enable testing" OFF)
option(RANDO_BENCHMARK "Enable benchmarks" OFF)

message("-- Configuring rando version: ${PROJECT_VERSION}")
message("--   Options:")
message("--     RANDO_TEST: ${RANDO_TEST}")
message("--     RANDO_BENCHMARK: ${RANDO_BENCHMARK}")

add_library(rando INTERFACE)

target_include_directories(rando INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

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

set(INCLUDE_INSTALL_DIR "include")
set(LIB_INSTALL_DIR "lib/")
set(BIN_INSTALL_DIR "bin/")

set(CONFIG_INSTALL_DIR "lib/cmake/${PROJECT_NAME}")
set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(VERSION_CONFIG "${GENERATED_DIR}/${PROJECT_NAME}ConfigVersion.cmake")
set(PROJECT_CONFIG "${GENERATED_DIR}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")

set(NAMESPACE "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${VERSION_CONFIG}" VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion
)

configure_file("${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in" "${PROJECT_CONFIG}" @ONLY)

install(
    TARGETS rando
    EXPORT ${TARGETS_EXPORT_NAME}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
    RUNTIME DESTINATION ${BIN_INSTALL_DIR}
    INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR})

install(
  DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
  DESTINATION ${INCLUDE_INSTALL_DIR}
  FILES_MATCHING PATTERN "*.h")

install(
    FILES "${PROJECT_CONFIG}" "${VERSION_CONFIG}"
    DESTINATION "${CONFIG_INSTALL_DIR}")

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${NAMESPACE}"
    DESTINATION "${CONFIG_INSTALL_DIR}")
