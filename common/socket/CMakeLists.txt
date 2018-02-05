cmake_minimum_required(VERSION 3.7)
project(psu_socket_library)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra")

set (SOCKET_SOURCE_DIR src)

set (SOCKET_COMMON
        ${SOCKET_SOURCE_DIR}/Socket.c
        ${SOCKET_SOURCE_DIR}/TcpListener.c
        ${SOCKET_SOURCE_DIR}/TcpSocket.c
        ${SOCKET_SOURCE_DIR}/accept.c
        ${SOCKET_SOURCE_DIR}/allocator.c
        ${SOCKET_SOURCE_DIR}/bind.c
        ${SOCKET_SOURCE_DIR}/close.c
        ${SOCKET_SOURCE_DIR}/connect.c
        ${SOCKET_SOURCE_DIR}/get_local.c
        ${SOCKET_SOURCE_DIR}/get_remote.c
        ${SOCKET_SOURCE_DIR}/init.c
        ${SOCKET_SOURCE_DIR}/listen.c
        ${SOCKET_SOURCE_DIR}/open.c
        ${SOCKET_SOURCE_DIR}/receive.c
        ${SOCKET_SOURCE_DIR}/send.c
        ${SOCKET_SOURCE_DIR}/set_address.c
        Socket.h
        TcpListener.h
        TcpSocket.h
        SocketSelector.h
        src/Sockselector.c
        src/select_add.c
        src/selector_clear.c
        src/select_remove.c
        src/select_wait.c
        src/select_ready.c TcpPacket.h src/packet.c)

add_library(socket STATIC ${SOCKET_COMMON})
