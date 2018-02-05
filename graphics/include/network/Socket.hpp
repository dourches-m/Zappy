/*
** Socket.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jun 25 14:24:40 2017 Sylvain Chaugny
** Last update Mon Jun 26 18:01:49 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_SOCKET_HPP_
# define			CPP_ZAPPY_SOCKET_HPP_

# include			<netinet/in.h>
# include			<string>

namespace			zappy
{
  namespace			network
  {
    class			Socket
    {
    private:
      int			_port;
      std::string		_addr;
      std::string		_proto_name;
      struct protoent		*_proto;
      struct sockaddr_in	_s_in;
      int			_s_in_size;
      int			_fd;
      std::string		_data;

    public:
      Socket(int port = 0, std::string const &addr = "", std::string const &proto_name = "TCP");
      Socket(Socket const &ref);
      Socket		&operator=(Socket const &ref);
      virtual ~Socket();

      void			init();
      void			connect();
      void			close();

      void			setPort(int port) { _port = port; }
      void			setAddr(std::string const &addr) { _addr = addr; }
      int			getFd() const { return _fd; }
    };
  };
};

#endif				/* !CPP_ZAPPY_SOCKET_HPP_ */
