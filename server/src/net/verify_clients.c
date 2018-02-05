/*
** verify_clients.c for zappy in /home/anthony/repository/zappy/verify_clients.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 28 17:51:42 2017 Anthony LECLERC
** Last update mer. juin 28 17:51:42 2017 Anthony LECLERC
*/

#include 		<stdio.h>
#include		"debug.h"
#include 		"serverinfo.h"

int			verify_read(t_zserver *server, t_client *client)
{
  if (select_ready(&server->selector, &client->socket.socket, READ_SET))
  {
    if (client->read_data(client) == 0)
    {
      if (client->player == NULL)
        try_register(server, client);
    }
    else
    {
      deconnect_client(server, client);
      return (1);
    }
  }
  return (0);
}

static void		verify_write(t_zserver *server, t_client *client)
{
  if (select_ready(&server->selector, &client->socket.socket, WRITE_SET))
  {
    if (client->write_data(client) != 0)
    {
      DLOG("[PLAYER]: Fail while writing data\n");
      deconnect_client(server, client);
    }
    else
    {
      if (circbuffer_isempty(client->output))
      {
        select_remove(&server->selector, &client->socket.socket);
        select_add(&server->selector, &client->socket.socket, READ_SELECT);
      }
    }
  }
}

void			verify_clients(t_zserver *server)
{
  t_list_item		*item;
  t_client		*client;

  item = server->clients->first;
  while (item != NULL)
  {
    client = item->data;
    item = item->next;
    if (verify_read(server, client) == 0)
      verify_write(server, client);
  }
}
