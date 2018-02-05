/*
** protocol.h for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Jun 20 18:31:27 2017 Sylvain Chaugny
** Last update Sat Jul  1 23:52:40 2017 Anthony LECLERC
*/

#ifndef				PROTOCOL_H_
# define			PROTOCOL_H_

/*
** INCLUDES
*/

# include			<stddef.h>
# include			<stdbool.h>
# include			<stdint.h>

/*
** CONSTANTS
*/

# define			TNA_MAX_SIZE	(64)

/*
** PROTOCOL ENUMS
*/

enum				e_protocol_cmd
  {
    E_CMD_PLAYER		= 1,
    E_CMD_INCANTATION,
    E_CMD_EGG,
    E_CMD_SERVER,
    E_CMD_DATA,
  };

enum				e_protocol_player
  {
    E_PLAYER_NEW		= 1,
    E_PLAYER_MOVE,
    E_PLAYER_EXPULSE,
    E_PLAYER_BROADCAST,
    E_PLAYER_FORK,
    E_PLAYER_DELETE_RESSOURCE,
    E_PLAYER_GET_RESSOURCE,
    E_PLAYER_DIE,
    E_PLAYER_NEW_FOR_EGG,
    E_PLAYER_ACTIONS,
  };

enum				e_protocol_incantation
  {
    E_INCANTATION_BEGIN		= 1,
    E_INCANTATION_END,
    E_INCANTATION_ACTIONS,
  };

enum				e_protocol_egg
  {
    E_EGG_HATCH			= 1,
    E_EGG_DIE,
    E_EGG_ACTIONS
  };

enum				e_protocol_server
  {
    E_SERVER_GAME_END		= 1,
    E_SERVER_MSG,
    E_SERVER_UNKNOWN_CMD,
    E_SERVER_BAD_PARAMS,
    E_SERVER_ACTIONS,
  };

/*
** MISCELLANEOUS ENUMS
*/

enum				e_ressources
  {
    E_RESSOURCE_FOOD		= 1,
    E_RESSOURCE_LINEMATE,
    E_RESSOURCE_DERAUMERE,
    E_RESSOURCE_SIBUR,
    E_RESSOURCE_MENDIANE,
    E_RESSOURCE_PHIRAS,
    E_RESSOURCE_THYSTAME,
    E_RESSOURCES,
  };

typedef enum			e_player_direction
  {
    E_DIRECTION_NORTH		= 1,
    E_DIRECTION_SOUTH,
    E_DIRECTION_EAST,
    E_DIRECTION_WEST,
    E_DIRECTIONS,
  }				t_player_direction;

/*
** MISCELLANEOUS STRUCTURES
*/

typedef struct			s_position
{
  int32_t			x;
  int32_t			y;
}				t_position;

typedef struct			s_dimensions
{
  int32_t			width;
  int32_t			height;
}				t_dimensions;

typedef struct			s_cell
{
  t_position			pos;
  int32_t			ressources[E_RESSOURCES];
}				t_cell;

typedef struct			s_inventory
{
  int32_t			ressources[E_RESSOURCES];
}				t_inventory;

typedef struct			s_player_infos
{
  int32_t			id;
  int32_t			level;
  enum e_player_direction 	dir;
  int32_t			team_id;
  t_inventory			inventory;
  t_position			pos;
}				t_player_infos;

typedef struct			s_egg_infos
{
  int32_t			id;
  int32_t		        team_id;
  bool				dead;
  bool				created;
  char				pad[sizeof(long) - sizeof(bool) * 2];
  t_position			pos;
}				t_egg_infos;

typedef struct			s_team_infos
{
  int32_t			team_id;
  int32_t			max_slots;
  int32_t			free_slots;
  char				name[128];
}				t_team_infos;

/*
** PROTOCOL STRUCTURES
*/

typedef struct			s_protocol_base
{
  uint32_t			size;
  enum e_protocol_cmd		type;
}				t_protocol_base;

typedef struct			s_protocol_player
{
  uint64_t			frame;
  int32_t			player_id;
  enum e_protocol_player	action;
}				t_protocol_player;

typedef struct			s_protocol_incantation
{
  uint64_t			frame;
  int32_t			player_id;
  enum e_protocol_incantation	action;
}				t_protocol_incantation;

typedef struct			s_protocol_egg
{
  uint64_t			frame;
  int32_t			player_id;
  enum e_protocol_egg		action;
}				t_protocol_egg;

typedef struct			s_protocol_server
{
  uint64_t			frame;
  int32_t			player_id;
  enum e_protocol_server	action;
}				t_protocol_server;

typedef struct			s_protocol_data
{
  t_dimensions			dimensions;
  int32_t			init_frame;
  int32_t			nb_player;
  int32_t			nb_egg;
  int32_t			nb_team;
}				t_protocol_data;

#endif				/* !PROTOCOL_H_ */
