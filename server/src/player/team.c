/*
** team.c for zappy in /home/anthony/repository/zappy/team.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 13:21:27 2017 Anthony LECLERC
** Last update jeu. juin 22 13:21:27 2017 Anthony LECLERC
*/

#include 	<stdlib.h>
#include 	"utils.h"
#include 	"team.h"

t_team		*create_team(char const *name, uint32_t size)
{
  t_team	*team;

  team = myalloc(sizeof(t_team));
  team->player = NULL;
  team->name = mstrdup(name);
  team->nb_players = 0;
  team->slots = size;
  team->id = 0;
  return (team);
}

void		destruct_team(t_team *team)
{
  free(team->player);
  free(team);
}