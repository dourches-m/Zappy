/*
** send_to_players.c for psu_zappy in /home/baldas/Prog/repos/tek2/psu/PSU_2016_zappy
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Sun Jun 25 14:54:49 2017 Hugo Baldassin
** Last update Sun Jun 25 14:54:51 2017 Hugo Baldassin
*/

#include	"list/list_item.h"
#include 	"player.h"
#include 	"utils.h"

void 		send_to_players(t_list_item *list, char *reply)
{
  t_list_item	*players;
  t_player	*player;

  players = list;
  while (players)
    {
      player = (t_player *)players->data;
      send_data(player->net->output, reply);
      players = players->next;
    }
}