cmake_minimum_required(VERSION 3.10)
project(IMGPROC_NATIVE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(IMGPROC ${SOURCES})
