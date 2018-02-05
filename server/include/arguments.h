/*
** arguments.h for zappy in /home/anthony/repository/zappy/arguments.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 21:41:46 2017 Anthony LECLERC
** Last update lun. juin 19 21:41:46 2017 Anthony LECLERC
*/

#ifndef		ARGUMENTS_H_
# define 	ARGUMENTS_H_

# include 	"serverinfo.h"

int		compare(char const *s1, char const *s2);

void		print_arguments(t_servinfo const *infos);

/*
** Parse command line arguments and set default values.
*/

int		parse_arguments(int ac, char **av, t_servinfo *infos);

int		get_port_command(t_servinfo *infos, int ac, char **av);

int		get_teams_command(t_servinfo *infos, int ac, char **av);

int		get_nbplayer_command(t_servinfo *infos, int ac, char **av);

int		get_dimensions_command(t_servinfo *infos, int ac, char **av);

int		get_freq_command(t_servinfo *infos, int ac, char **av);

void		usage(char const *binary_name);

#endif 		/* ARGUMENTS_H_ */
