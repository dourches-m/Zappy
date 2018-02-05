/*
** Log.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 19:38:52 2017 Sylvain Chaugny
** Last update Thu Jun 22 19:40:47 2017 Sylvain Chaugny
*/

#include	<iostream>
#include	"utl/Log.hpp"

void		zappy::utl::Log::log(std::string const &s)
{
  std::cout << "[LOG] " << s << std::endl;
}

void		zappy::utl::Log::warning(std::string const &s)
{
  std::cerr << "[WARNING] " << s << std::endl;
}

void		zappy::utl::Log::error(std::string const &s)
{
  std::cerr << "[ERROR] " << s << std::endl;
}

void		zappy::utl::Log::usage(const char *prog)
{
  std::cout << "Usage: " << prog << " -p [connection port] -h [connection IP address]" << std::endl;
}
