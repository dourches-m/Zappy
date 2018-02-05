/*
** Timer.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jun 30 18:47:01 2017 Sylvain Chaugny
// Last update Sat Jul  1 23:23:52 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_TMER_HPP_
# define			CPP_ZAPPY_TMER_HPP_

# include			<chrono>

namespace			zappy
{
  namespace			utl
  {
    class			Timer
    {
    public:
      typedef std::chrono::steady_clock clock;

    private:
      clock _clock;
      clock::time_point _action_time;
      double _delay;

    public:
      Timer();
      virtual ~Timer();

      void			setDelay(int frames_per_second);
      bool			isAllowed();
    };
  };
};

#endif				/* !CPP_ZAPPY_TMER_HPP_ */
