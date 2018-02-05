/*
** TCP.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jun 28 17:22:33 2017 Sylvain Chaugny
** Last update Wed Jun 28 20:33:46 2017 Sylvain Chaugny
*/

#include <cstddef>
#include		"utl/TCP.hpp"
#include		"network/NetworkWrapper.hpp"

size_t			zappy::utl::TCP::receive(int fd, void *data, int size)
{
  int			tmp;
  int			read;
  unsigned char		*buf;

  buf = reinterpret_cast<unsigned char *>(data);
  tmp = 0;
  read = 1;
  while (tmp < size && read > 0)
    {
      buf += tmp;
      read = network::NetworkWrapper::recv(fd, buf, size - tmp);
      tmp += read;
    }
  return read ? tmp : -1;
}

size_t			zappy::utl::TCP::send(int fd, void *data, int size)
{
  int			tmp;
  int			written;
  unsigned char		*buf;

  tmp = 0;
  written = 1;
  buf = reinterpret_cast<unsigned char *>(data);
  while (tmp < size && written > 0)
    {
      buf += tmp;
      written = network::NetworkWrapper::send(fd, buf, size - tmp);
      tmp += written;
    }
  return written ? 0 : 1;
}
