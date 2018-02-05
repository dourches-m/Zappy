/*
** Package.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Jun 26 17:38:35 2017 Sylvain Chaugny
** Last update Fri Jun 30 18:14:47 2017 Sylvain Chaugny
*/

#include		"package/Package.hpp"

zappy::package::Package::Package() :
  _size(0)
{
}

zappy::package::Package::Package(Package const &ref) :
  _size(ref._size),
  _props(ref._props)
{
}

zappy::package::Package	&zappy::package::Package::operator=(Package const &ref)
{
  _size = ref._size;
  _buffer = ref._buffer;
  _props = ref._props;
  return *this;
}

zappy::package::Package::~Package()
{
}

void			zappy::package::Package::init(size_t size)
{
  _size = size;
  _buffer.init(size);
}

size_t			zappy::package::Package::getSize() const
{
  return _size;
}

void			zappy::package::Package::clear()
{
  _props.clear();
  _buffer.clear();
  _size = 0;
}
