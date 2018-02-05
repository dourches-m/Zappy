cmake_minimum_required(VERSION 3.7)
project(psu_list_library)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra")

set (LIST_SOURCE_DIR src)

set (LIST_COMMON
        list.h
        list_item.h
        ${LIST_SOURCE_DIR}/list_delete.c
        ${LIST_SOURCE_DIR}/list_iter.c
        ${LIST_SOURCE_DIR}/list_init.c
        ${LIST_SOURCE_DIR}/list_insert.c
        ${LIST_SOURCE_DIR}/list_item_delete.c
        ${LIST_SOURCE_DIR}/list_item_init.c
        ${LIST_SOURCE_DIR}/list_pop.c
        ${LIST_SOURCE_DIR}/list_pushback.c
        ${LIST_SOURCE_DIR}/list_pushfront.c
        ${LIST_SOURCE_DIR}/list_map.c
        ${LIST_SOURCE_DIR}/list_find.c src/list_erase.c src/list_extract.c src/list_mem.c src/list_remove.c)

include_directories(..)

add_library(list STATIC ${LIST_COMMON})
