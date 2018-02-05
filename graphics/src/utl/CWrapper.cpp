/*
** CWrapper.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jun 25 14:37:41 2017 Sylvain Chaugny
** Last update Fri Jun 30 18:59:20 2017 Sylvain Chaugny
*/

#include		<unistd.h>
#include		<cstring>
#include		<errno.h>
#include		"utl/CWrapper.hpp"

const char		*zappy::utl::CWrapper::strerror()
{
  return ::strerror(errno);
}

int			zappy::utl::CWrapper::close(int fd)
{
  return ::close(fd);
}

int			zappy::utl::CWrapper::write(int fd, const void *msg, int size)
{
  return ::write(fd, msg, size);
}

int			zappy::utl::CWrapper::read(int fd, void *buf, int size)
{
  return ::read(fd, buf, size);
}

void			*zappy::utl::CWrapper::memset(void *p, int c, size_t n)
{
  return ::memset(p, c, n);
}

void		        zappy::utl::CWrapper::usleep(double delay)
{
  ::usleep(delay);
}
