/*
** TCP.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jun 28 17:20:27 2017 Sylvain Chaugny
** Last update Thu Jun 29 19:13:30 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_TCP_HPP_
# define			CPP_ZAPPY_TCP_HPP_

# include			<cstddef>
# include			<vector>

namespace			zappy
{
  namespace			utl
  {
    class			TCP
    {
    public:
      TCP() {}
      virtual ~TCP() {}

      static size_t		receive(int fd, void *data, int size);
      static size_t		send(int fd, void *data, int size);
    };
  };
};

#endif				/* !CPP_ZAPPY_TCP_HPP_ */
