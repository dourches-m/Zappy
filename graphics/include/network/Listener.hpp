/*
** Listener.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jun 25 18:11:40 2017 Sylvain Chaugny
// Last update Sun Jul  2 08:41:24 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_LISTENER_HPP_
# define			CPP_ZAPPY_LISTENER_HPP_

# include			<sys/select.h>
# include			"network/Socket.hpp"
# include			"utl/Buffer.hpp"

namespace			zappy
{
  namespace			network
  {
    class			Listener
    {
    private:
      int			_fd;
      fd_set			_set;
      fd_set			_set_ready;
      ssize_t			_timeout;
      utl::Buffer		_buffer;

    public:
      Listener();
      virtual ~Listener();

      void			init(Socket const &sock, ssize_t timeout = 1000);
      int			isRunning();
      bool			isSet();

      void			bufferize();
      utl::Buffer		&getBuffer();
      void			replyToWelcome();
    };
  };
};

#endif				/* !CPP_ZAPPY_LISTENER_HPP_ */
