cmake_minimum_required(VERSION 3.7)
project(zappy_server)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra -L../common/lib -DSERVDEBUG -DEGGDEBUG")

include_directories(include)
include_directories(../common)

set(SOURCE_FILES
        src/main.c
        src/arguments/usage.c
        include/arguments.h
        include/serverinfo.h
        include/debug.h
        src/arguments/parse.c
        src/arguments/getport.c
        src/arguments/compare.c
        src/arguments/getteams.c
        src/utils/myalloc.c
        include/utils.h
        src/arguments/getdims.c
        src/arguments/getfreq.c
        src/utils/mstrdup.c
        src/arguments/getnbplayer.c
        include/protocol/packet.h
        include/map/map.h
        include/player.h
        include/direction.h
        include/team.h
        src/map/create_map.c
        src/map/generate.c
        include/pos.h
        include/commands.h
        include/item_type.h
        src/commands/command_utils.c
        src/inventory/inventory_utils.c
        src/player/player.c
        include/client.h
        src/net/create_client.c
        src/utils/rand_init.c
        src/server/server.c
        src/player/team.c
        src/server/server_loop.c
        src/server/connect_client.c
        src/server/deconnect_client.c
        src/server/try_register.c
        src/server/read_data.c
        src/graphic/create_graphic.c
        include/graphic.h
        src/commands/commands.c
        src/utils/free_2d_array.c
        src/commands/exec/exec_fork.c
        src/commands/exec/exec_right.c
        src/commands/exec/exec_forward.c
        src/commands/exec/exec_left.c
        src/commands/exec/exec_set.c
        src/utils/send_data.c
        src/commands/exec/exec_eject.c
        src/commands/exec/exec_take.c
        src/commands/exec/exec_connect_nbr.c
        src/utils/nb_len.c
        src/utils/my_str_to_wordtab.c
        src/commands/exec/exec_inventory.c
        src/commands/exec/exec_incantation.c
        include/incant.h
        src/utils/get_tile_nb_player.c
        src/map/egg.c
        include/map/egg.h
        src/net/is_free_client.c
        src/player/update.c
        src/utils/get_tile_nb_player.c
        src/commands/exec/exec_look.c
        src/utils/send_to_players.c
        src/commands/exec/exec_look_utils.c
        src/utils/concat_strings.c
        src/utils/convert_to_real_pos.c
        src/server/frequency.c
        include/frequency.h
        src/net/verify_clients.c
        src/player/handle_inputs.c
        src/server/update.c
        src/player/death.c
        src/server/time.c
        src/net/register_player.c
        src/net/register_graphic.c
        src/graphic/write_to.c
        src/net/write_to.c
        src/player/write_to.c
        src/commands/exec/exec_command.c
        src/commands/exec/exec_broadcast.c
        src/utils/spawn_resource.c
        ../common/protocol.h
        src/graphic/direction.c
        src/graphic/connect_player.c
        src/graphic/broadcast.c
        src/graphic/init/init_protocol.c
        src/graphic/player_ressource.c
        src/graphic/death.c
        include/protocol/proto_player.h
        src/graphic/egg.c
        include/protocol/proto_egg.h
        src/graphic/connect.c
        include/protocol/proto_data.h
        src/graphic/init/incant.c
        include/protocol/proto_incant.h)

add_executable(zappy_server ${SOURCE_FILES})

target_link_libraries(zappy_server m)
target_link_libraries(zappy_server list)
target_link_libraries(zappy_server buffer)
target_link_libraries(zappy_server socket)
