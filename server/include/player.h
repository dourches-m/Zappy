/*
** Player.h for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Tue Jun 20 18:58:15 2017 Hugo Baldassin
** Last update Wed Jun 21 13:58:37 2017 Hugo Baldassin
*/

#ifndef			ZAPPY_PLAYER_H
# define 		ZAPPY_PLAYER_H

# include		"direction.h"
# include		"pos.h"
# include		"item_type.h"
# include		"commands.h"
# include		"client.h"

typedef struct		s_command t_command;

struct			s_team;

typedef struct		s_item
{
  unsigned int		nb;
  t_item_type		type;
}			t_item;

typedef struct		s_player
{
  t_client		*net;
  struct s_team		*team;
  struct s_item		inventory[7];
  unsigned int		lvl;
  t_direction		dir;
  size_t		life_time;
  t_pos			pos;
  t_command		*cmd_list;
  unsigned int		id;
  struct s_player	*next;
}			t_player;

# define		CYCLE_FOOD	126

/*
**	INVENTORY UTILS
*/

void		init_inventory(t_item *inventory);
void		edit_item_quantity(t_player *player, t_item_type type,
				   int val);
t_item_type	is_an_item(char *str);

/*
**	PLAYER LIST UTILS
*/

t_player 	*init_player(t_pos *pos, struct s_team *team);
void	 	add_player(t_player **list, t_player *player);
void		remove_player(t_player **list, t_player *player);

#endif 			/* !ZAPPY_PLAYER_H */
