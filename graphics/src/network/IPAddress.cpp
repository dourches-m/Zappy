/*
** IPAddress.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 19:50:50 2017 Sylvain Chaugny
** Last update Thu Jun 22 21:00:52 2017 Sylvain Chaugny
*/

#include		<arpa/inet.h>
#include		"network/IPAddress.hpp"
#include		"network/NetworkWrapper.hpp"

zappy::network::IPAddress::IPAddress(std::string const &str) :
  _raw(str)
{
}

zappy::network::IPAddress const &zappy::network::IPAddress::operator=(zappy::network::IPAddress const &ref)
{
  _raw = ref._raw;
  _addr = ref._addr;
  return *this;
}

zappy::network::IPAddress::~IPAddress()
{
}

int			zappy::network::IPAddress::load()
{
  char			tmp[128];

  if (NetworkWrapper::inet_pton(AF_INET, _raw.c_str(), tmp))
    {
      _addr = _raw;
      return 0;
    }
  return 1;
}

std::string const	&zappy::network::IPAddress::get()
{
  return _addr;
}

void			zappy::network::IPAddress::setRawAddr(std::string const &raw)
{
  _raw = raw;
  _addr.clear();
}
