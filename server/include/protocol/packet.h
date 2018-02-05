/*
** packet.h for zappy in /home/anthony/repository/zappy/packet.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mar. juin 20 17:55:03 2017 Anthony LECLERC
** Last update mar. juin 20 17:55:03 2017 Anthony LECLERC
*/

#ifndef  	ZAPPY_PACKET_H
# define 	ZAPPY_PACKET_H

struct 		s_socket;

typedef struct	s_packet
{
  long		size;
  char		*data;
}		t_packet;

typedef enum	e_cmdtype
{
  MSZ,
  BCT,
  BCT_ELEM,
  TNA,
  PNW,
  PPO,
  PLV,
  PIN,
  PEX,
  PBC,
  PIC,
  PIE,
  PFK,
  PDR,
  PGT,
  PDI,
  ENW,
  EHT,
  EBO,
  EDI,
  SGT,
  MSGT,
  SEG,
  SMG,
  SUC,
  SBP
}		t_cmdtype;

typedef struct	s_zppacket
{
  t_cmdtype	cmd;
}		t_zppacket;

int		send_packet(struct s_socket *sock, t_packet *packet);

int		receive_packet(struct s_socket *sock, t_packet *packet);

#endif		/* ZAPPY_PACKET_H */
