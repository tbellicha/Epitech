cmake_minimum_required(VERSION 3.17.0)

project(HelloWorld LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(lib/ikea)

add_subdirectory(src)

if (BUILD_TEST_SUITE)
    find_package(Criterion REQUIRED)
    enable_testing()
    add_subdirectory(tests)
endif()
