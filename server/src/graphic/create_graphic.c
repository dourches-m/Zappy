/*
** create_graphic.c for zappy in /home/anthony/repository/zappy/create_graphic.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 12:31:37 2017 Anthony LECLERC
** Last update ven. juin 23 12:31:37 2017 Anthony LECLERC
*/

#include 		"utils.h"
#include		"graphic.h"

t_graphic		*create_graphic(t_client *client)
{
  t_graphic		*graphic;

  graphic = myalloc(sizeof(t_graphic));
  graphic->client = client;
  client->read_data = read_graphics;
  return (graphic);
}