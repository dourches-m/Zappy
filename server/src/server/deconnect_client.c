/*
** deconnect_client.c for zappy in /home/anthony/repository/zappy/deconnect_client.c
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 23 11:46:31 2017 Anthony LECLERC
** Last update ven. juin 23 11:46:31 2017 Anthony LECLERC
*/

#include 	<debug.h>
#include 	<stdio.h>
#include 	"client.h"
#include 	"serverinfo.h"

int		deconnect_client(t_zserver *server, t_client *client)
{
  SERVLOG("Client: Deconnection\n");
  select_remove(&server->selector, &client->socket.socket);
  list_erase_item(server->clients, client, destruct_client);
  return (0);
}