cmake_minimum_required(VERSION 3.10)
project(IMGPROC_NATIVE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

# set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")
message("Cmake build type after setting: ${CMAKE_BUILD_TYPE}")

# Debug mode ASAN flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer -g")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer")
set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer")

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")
link_directories(${OpenCV_LIBRARY_DIRS})

add_executable(IMGPROC ${SOURCES})
target_link_libraries(IMGPROC ${OpenCV_LIBS})