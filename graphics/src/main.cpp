/*
** main.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/src
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 14:52:33 2017 Sylvain Chaugny
// Last update Sun Jul  2 14:24:48 2017 Sylvain Chaugny
*/

#include	"Core.hpp"

int		main(const int, const char **av, const char **ae)
{
  zappy::Core	core;

  if (core.init(av, ae))
    return (1);
  if (core.loop())
    return (1);
  return core.stop();
}
