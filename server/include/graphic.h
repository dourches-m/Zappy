/*
** graphic.h for zappy in /home/anthony/repository/zappy/graphic.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 12:33:08 2017 Anthony LECLERC
** Last update ven. juin 23 12:33:08 2017 Anthony LECLERC
*/

#ifndef 		ZAPPY_GRAPHIC_H
# define 		ZAPPY_GRAPHIC_H

# include		"client.h"
# include		"player.h"
# include		"protocol/proto_player.h"
# include		"protocol/proto_data.h"
# include		"protocol/proto_egg.h"
# include		"protocol/proto_incant.h"

int			write_packet(void *dest, void *packet,
					size_t max_size);

void			init_base_protocol(t_protocol_base *base,
					       uint32_t size,
					       enum e_protocol_cmd type);

void			init_incant_protocol(t_protocol_incantation *proto,
						 enum e_protocol_incantation);

void			init_egg_protocol(t_protocol_egg *proto,
					      enum e_protocol_egg);

void			init_server_protocol(t_protocol_server *proto,
					      enum e_protocol_server);

typedef struct		s_graphic
{
  t_client		*client;
}			t_graphic;

t_graphic		*create_graphic(t_client *client);

int			read_graphics(t_client *self);

void			gr_base_infos(t_graphic *graphic, t_map *map,
					  t_team **teams,
					  unsigned int nteam);

int			gr_player_infos(t_graphic *graphic, t_player *player);

int			gr_send_player_direction(t_graphic *graphic,
						     t_player *player);

void			gr_player_set(t_graphic *graphic,
					 t_item_type type);

void			gr_player_get(t_graphic *graphic,
					 t_item_type type);

void			gr_player_dies(t_graphic *graphic);

enum e_ressources	convert_ressource(t_item_type type);

enum e_player_direction convert_dir(t_direction dir);

#endif /* ZAPPY_GRAPHIC_H */
