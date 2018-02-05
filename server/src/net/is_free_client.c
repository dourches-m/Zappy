/*
** is_free_client.c for zappy in /home/anthony/repository/zappy/is_free_client.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 26 12:33:23 2017 Anthony LECLERC
** Last update lun. juin 26 12:33:23 2017 Anthony LECLERC
*/

#include 		"player.h"
#include		"map/map.h"

int			is_free_client(void *player)
{
  return (((t_player *)player)->net == NULL);
}