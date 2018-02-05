/*
** Log.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 14:44:57 2017 Sylvain Chaugny
** Last update Thu Jun 22 19:40:04 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_LOG_HPP_
# define		CPP_ZAPPY_LOG_HPP_

# include		<string>

namespace		zappy
{
  namespace		utl
  {
    class		Log
    {
    public:
      Log() {}
      virtual ~Log() {}

      static void	log(std::string const &s);
      static void	warning(std::string const &s);
      static void	error(std::string const &s);
      static void	usage(const char *prog);
    };
  };
};

#endif			/* !CPP_ZAPPY_LOG_HPP_ */
