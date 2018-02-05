/*
** Buffer.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jun 30 01:50:51 2017 Sylvain Chaugny
** Last update Fri Jun 30 17:16:40 2017 Sylvain Chaugny
*/

#include		"utl/Buffer.hpp"

zappy::utl::Buffer::Buffer() :
  _off_begin(0)
{
  _data.clear();
}

zappy::utl::Buffer::Buffer(Buffer const &ref)
{
  _data = ref._data;
  _part = ref._part;
  _off_begin = ref._off_begin;
}

zappy::utl::Buffer	&zappy::utl::Buffer::operator=(Buffer const &ref)
{
  _data = ref._data;
  _part = ref._part;
  _off_begin = ref._off_begin;
  return *this;
}

zappy::utl::Buffer::~Buffer()
{
}

void			zappy::utl::Buffer::addData(std::vector<char> const &data)
{
   _data.insert(_data.end(), data.begin(), data.end());
}

std::vector<char>	&zappy::utl::Buffer::getData()
{
  return _data;
}

std::vector<char>	&zappy::utl::Buffer::getPart(size_t from, size_t size)
{
  from = from >= _data.size() ? _data.size() - 1 : from;
  size = size > _data.size() ? _data.size() - 1: size;
  _part.clear();
  _part.resize(size);
  std::copy(_data.begin() + from, _data.begin() + from + size, _part.begin());
  return _part;
}

size_t			zappy::utl::Buffer::getOffBegin() const
{
  return _off_begin;
}

void			zappy::utl::Buffer::addToOffBegin(size_t add)
{
  _off_begin += add;
}

void			zappy::utl::Buffer::init(size_t size)
{
  _data.clear();
  _data.resize(size);
}

void			zappy::utl::Buffer::clear()
{
  _off_begin = 0;
  _data.clear();
  _part.clear();
}
