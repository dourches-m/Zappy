cmake_minimum_required(VERSION 3.7)
project(psu_circular_buffer_library)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra")

set (CIRCBUFFER_SOURCE_DIR src)

set (CIRCBUFFER_COMMON
        ${CIRCBUFFER_SOURCE_DIR}/create.c
        circbuffer.h
        src/delete.c src/reserve.c
        src/push.c bipbuffer.h
        src/unused.c
        src/discard.c
        src/used.c
        src/front.c
        src/new_line.c
        src/switch.c main.c src/msg_to_buffer.c src/extract.c src/resize.c)

add_library(circbuffer STATIC ${CIRCBUFFER_COMMON})
add_executable(buffer_test main.c)
target_link_libraries(buffer_test circbuffer)
