##
## sources.mk for  in /home/anthony/Documents/repository/psu/PSU_2016_zappy/common/buffer
## 
## Made by Anthony LECLERC
## Login   <anthony.leclerc@epitech.net>
## 
## Started on  Sun Jul  2 19:26:25 2017 Anthony LECLERC
## Last update Sun Jul  2 23:23:15 2017 Anthony LECLERC
##

SRC			+=	./src/server/deconnect_client.c
SRC			+=	./src/server/time.c
SRC			+=	./src/server/update.c
SRC			+=	./src/server/frequency.c
SRC			+=	./src/server/try_register.c
SRC			+=	./src/server/server_loop.c
SRC			+=	./src/server/server.c
SRC			+=	./src/server/read_data.c
SRC			+=	./src/server/connect_client.c
SRC			+=	./src/main.c
SRC			+=	./src/map/generate.c
SRC			+=	./src/map/create_map.c
SRC			+=	./src/map/egg.c
SRC			+=	./src/arguments/usage.c
SRC			+=	./src/arguments/getnbplayer.c
SRC			+=	./src/arguments/getport.c
SRC			+=	./src/arguments/compare.c
SRC			+=	./src/arguments/getfreq.c
SRC			+=	./src/arguments/getdims.c
SRC			+=	./src/arguments/parse.c
SRC			+=	./src/arguments/getteams.c
SRC			+=	./src/player/handle_inputs.c
SRC			+=	./src/player/update.c
SRC			+=	./src/player/write_to.c
SRC			+=	./src/player/player.c
SRC			+=	./src/player/team.c
SRC			+=	./src/player/handle_outputs.c
SRC			+=	./src/player/death.c
SRC			+=	./src/graphic/connect.c
SRC			+=	./src/graphic/direction.c
SRC			+=	./src/graphic/egg.c
SRC			+=	./src/graphic/init/init_protocol.c
SRC			+=	./src/graphic/init/incant.c
SRC			+=	./src/graphic/player_ressource.c
SRC			+=	./src/graphic/connect_player.c
SRC			+=	./src/graphic/death.c
SRC			+=	./src/graphic/create_graphic.c
SRC			+=	./src/graphic/broadcast.c
SRC			+=	./src/net/register_graphic.c
SRC			+=	./src/net/write_to.c
SRC			+=	./src/net/create_client.c
SRC			+=	./src/net/register_player.c
SRC			+=	./src/net/verify_clients.c
SRC			+=	./src/net/is_free_client.c
SRC			+=	./src/utils/spawn_resource.c
SRC			+=	./src/utils/nb_len.c
SRC			+=	./src/utils/concat_strings.c
SRC			+=	./src/utils/send_to_players.c
SRC			+=	./src/utils/convert_to_real_pos.c
SRC			+=	./src/utils/my_str_to_wordtab.c
SRC			+=	./src/utils/rand_init.c
SRC			+=	./src/utils/myalloc.c
SRC			+=	./src/utils/mstrdup.c
SRC			+=	./src/utils/send_data.c
SRC			+=	./src/utils/get_tile_nb_player.c
SRC			+=	./src/utils/free_2d_array.c
SRC			+=	./src/commands/commands.c
SRC			+=	./src/commands/exec/exec_connect_nbr.c
SRC			+=	./src/commands/exec/exec_left.c
SRC			+=	./src/commands/exec/exec_look_utils.c
SRC			+=	./src/commands/exec/exec_set.c
SRC			+=	./src/commands/exec/exec_inventory.c
SRC			+=	./src/commands/exec/exec_eject.c
SRC			+=	./src/commands/exec/exec_fork.c
SRC			+=	./src/commands/exec/exec_command.c
SRC			+=	./src/commands/exec/exec_incantation.c
SRC			+=	./src/commands/exec/exec_take.c
SRC			+=	./src/commands/exec/exec_forward.c
SRC			+=	./src/commands/exec/exec_look.c
SRC			+=	./src/commands/exec/exec_right.c
SRC			+=	./src/commands/exec/exec_broadcast.c
SRC			+=	./src/commands/command_utils.c
SRC			+=	./src/inventory/inventory_utils.c


SRC			+=	../common/buffer/src/delete.c
SRC			+=	../common/buffer/src/new_line.c
SRC			+=	../common/buffer/src/discard.c
SRC			+=	../common/buffer/src/extract.c
SRC			+=	../common/buffer/src/reserve.c
SRC			+=	../common/buffer/src/create.c
SRC			+=	../common/buffer/src/front.c
SRC			+=	../common/buffer/src/msg_to_buffer.c
SRC			+=	../common/buffer/src/used.c
SRC			+=	../common/buffer/src/switch.c
SRC			+=	../common/buffer/src/unused.c
SRC			+=	../common/buffer/src/push.c

SRC			+=	../common/list/src/list_pushback.c
SRC			+=	../common/list/src/list_item_init.c
SRC			+=	../common/list/src/list_delete.c
SRC			+=	../common/list/src/list_item_delete.c
SRC			+=	../common/list/src/list_init.c
SRC			+=	../common/list/src/list_extract.c
SRC			+=	../common/list/src/list_erase.c
SRC			+=	../common/list/src/list_find.c
SRC			+=	../common/list/src/list_pushfront.c
SRC			+=	../common/list/src/list_remove.c

SRC			+=	../common/socket/src/send.c
SRC			+=	../common/socket/src/select_remove.c
SRC			+=	../common/socket/src/select_wait.c
SRC			+=	../common/socket/src/packet.c
SRC			+=	../common/socket/src/connect.c
SRC			+=	../common/socket/src/bind.c
SRC			+=	../common/socket/src/select_add.c
SRC			+=	../common/socket/src/accept.c
SRC			+=	../common/socket/src/TcpListener.c
SRC			+=	../common/socket/src/TcpSocket.c
SRC			+=	../common/socket/src/get_local.c
SRC			+=	../common/socket/src/select_ready.c
SRC			+=	../common/socket/src/Sockselector.c
SRC			+=	../common/socket/src/get_remote.c
SRC			+=	../common/socket/src/close.c
SRC			+=	../common/socket/src/set_address.c
SRC			+=	../common/socket/src/allocator.c
SRC			+=	../common/socket/src/Socket.c
SRC			+=	../common/socket/src/init.c
SRC			+=	../common/socket/src/listen.c
SRC			+=	../common/socket/src/selector_clear.c
SRC			+=	../common/socket/src/receive.c
SRC			+=	../common/socket/src/open.c
