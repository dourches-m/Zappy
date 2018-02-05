/*
** Timer.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jun 30 18:48:27 2017 Sylvain Chaugny
// Last update Sat Jul  1 23:23:45 2017 Sylvain Chaugny
*/

#include		"utl/Timer.hpp"
#include		"utl/CWrapper.hpp"

zappy::utl::Timer::Timer() :
  _clock(),
  _action_time(_clock.now()),
  _delay(1000000)
{
}

zappy::utl::Timer::~Timer()
{
}

void			zappy::utl::Timer::setDelay(int frames_per_second)
{
  _delay = 1000000 / frames_per_second;
}

bool			zappy::utl::Timer::isAllowed()
{
  std::chrono::duration<double> time_span;
  bool			allowed;

  allowed = false;
  time_span = std::chrono::duration_cast<std::chrono::duration<double>>(_clock.now() - _action_time);
  if (time_span.count() * 1000000 >= _delay)
    {
      allowed = true;
      _action_time = _clock.now();
    }
  return allowed;
}
