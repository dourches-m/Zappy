cmake_minimum_required(VERSION 3.7)
project(zappy)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra -DCMDDEBUG")

set (CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR})
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)

include_directories(common)

add_subdirectory(common/buffer)
add_subdirectory(common/list)
add_subdirectory(common/socket)
add_subdirectory(zappy_server)

