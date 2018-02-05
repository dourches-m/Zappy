/*
** register_graphic.c for zappy in /home/anthony/repository/zappy/register_graphic.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 29 03:05:40 2017 Anthony LECLERC
** Last update Fri Jun 30 14:00:11 2017 Hugo Baldassin
*/

#include 	<string.h>
#include	<stdio.h>
#include	"debug.h"
#include	"serverinfo.h"

int		register_graphic(t_zserver *server, t_client *client,
				 char const *input)
{
  if (strcmp("GRAPHIC", input) != 0)
    return (1);
  server->graphic = create_graphic(client);
  client->read_data = read_graphics;
  client->player = NULL;
  DLOG("[CONNECTION] New graphic client connected.\n");
  return (0);
}
