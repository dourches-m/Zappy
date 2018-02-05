/*
** commands.h for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy/server/src
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Wed Jun 21 16:03:55 2017 Hugo Baldassin
** Last update Thu Jun 22 15:10:08 2017 Hugo Baldassin
*/

#ifndef  		ZAPPY_COMMANDS_H
# define  		ZAPPY_COMMANDS_H

# include 		<stdbool.h>
# include 		"player.h"
# include 		"team.h"
# include	 	"map/map.h"

typedef struct  	s_team t_team;
typedef struct 	 	s_player t_player;

typedef enum  		e_command_type
  {
    UNDEF = -1,
    FORWARD,
    RIGHT,
    LEFT,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT_NBR,
    FORK,
    EJECT,
    TAKE,
    SET,
    CHECK_INCANTATION,
    INCANTATION
  }		 	t_command_type;

typedef struct		s_command
{
  t_command_type	type;
  size_t		slots;
  char			*arg;
  size_t 		time_units;
  bool			active;
  struct s_command	*next;
}			t_command;

/*
**	COMMAND LIST
*/

void		 	add_command(t_command **list, t_command *node);
t_command 		*init_command(char const *strcmd, size_t frequency);
void	 		pop_command(t_command **list);

/*
**	COMMAND UTILS
*/

t_command_type 		is_a_command(char const *str);
unsigned int 		get_nb_commands(t_player *player);

char	 		*get_cmd(char const *str);
char	 		*get_arg(char const *str);

/*
**	COMMAND EXEC
*/

void	 		exec_command(t_player *player, t_map *map);

void 			exec_forward(t_player *player, t_map *map);
void	 		exec_right(t_player *player, t_map *map);
void 			exec_left(t_player *player, t_map *map);
void 			exec_look(t_player *player, t_map *map);
void 			exec_inventory(t_player *player, t_map *map);
void 			exec_broadcast(t_player *player, t_map *map);
void	 		exec_connect_nbr(t_player *player, t_map *map);
void	 		exec_fork(t_player *player, t_map *map);
void	 		exec_eject(t_player *player, t_map *map);
void 			exec_take(t_player *player, t_map *map);
void	 		exec_set(t_player *player, t_map *map);
void 			exec_check_incantation(t_player *player, t_map *map);
void	 		exec_incantation(t_player *player, t_map *map);

/*
**	COMMAND MISC
*/

void  			look_down(t_player *player, t_map *map, char **reply);
void 	 		look_up(t_player *player, t_map *map, char **reply);
void  			look_left(t_player *player, t_map *map, char **reply);
void 	 		look_right(t_player *player, t_map *map, char **reply);
void 	 		get_tile_content(t_map *map, t_pos *pos, char **reply);

#endif 	 		/* !ZAPPY_COMMANDS_H */
