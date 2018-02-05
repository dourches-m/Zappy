/*
** create_client.c for zappy in /home/anthony/repository/zappy/create_client.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 22 11:45:23 2017 Anthony LECLERC
** Last update jeu. juin 22 11:45:23 2017 Anthony LECLERC
*/

#include 		<stdlib.h>
#include 		"utils.h"
#include 		"client.h"

t_client		*create_client()
{
  t_client		*client;

  client = myalloc(sizeof(t_client));
  client->input = circbuffer_create(CLIENT_BUFFER_SIZE);
  if (client->input == NULL)
  {
    free(client);
    return (NULL);
  }
  client->output = circbuffer_create(CLIENT_BUFFER_SIZE);
  if (client->output == NULL)
  {
    circbuffer_delete(client->input);
    free(client);
    return (NULL);
  }
  client->read_data = NULL;
  client->write_data = NULL;
  client->player = NULL;
  return (client);
}

void			destruct_client(void *self)
{
  t_client		*client;

  client = self;
  if (client->player)
    client->player->net = NULL;
  client->player = NULL;
  close_socket(&client->socket.socket);
  circbuffer_delete(client->input);
  circbuffer_delete(client->output);
  free(client);
}