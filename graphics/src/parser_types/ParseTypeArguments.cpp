/*
** ParseTypeArguments.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/src
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 15:13:04 2017 Sylvain Chaugny
** Last update Mon Jun 26 20:18:29 2017 Sylvain Chaugny
*/

#include	"Exceptions.hpp"
#include	"parser_types/ParserTypeArguments.hpp"

int		zappy::parser::ParserTypeArguments::parseArgs(const char **)
{
  std::string   key;
  std::string   value;
  int		i;

  for (i = 1; _args && _args[i]; i++)
    {
      if (!_args[i + 1])
	throw zappy::exception::ParserTypeArgumentsException("bad arguments", _args[0]);
      key = _args[i];
      i++;
      value = _args[i];
      if (key == value || (key != "-p" && key != "-h"))
	throw zappy::exception::ParserTypeArgumentsException("bad options", _args[0]);
      _tab[key] = value;
    }
  if (i != 5)
    throw zappy::exception::ParserTypeArgumentsException("bad arguments", _args[0]);
  return 0;
}
