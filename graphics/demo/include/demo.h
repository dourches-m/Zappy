/*
** demo.h for zappy in /home/sylvain/PSU_2016_zappy/graphic_client/demo
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jul  2 20:33:34 2017 Sylvain Chaugny
** Last update Sun Jul  2 21:14:18 2017 Sylvain Chaugny
*/

#ifndef			C_ZAPPY_DEMO_H_
# define		C_ZAPPY_DEMO_H_

# include		"protocol.h"

int			demo_init_server(int			port);
int			demo_get_client(int			fd);
void			demo_welcome(int			fd);
void			demo_animation_1(int			fd);
void			demo_animation_2(int			fd);
void			demo_animation_3(int			fd);
void			demo_send_data_players(int		fd);
void			demo_send_data_teams(int		fd);
void			demo_send_data_cells(int		fd,
					     t_protocol_data	*data,
					     t_cell		*cells);
void			demo_send_data(int			fd);

#endif			/* !C_ZAPPY_DEMO_H_ */
