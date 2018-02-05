/*
** CWrapper.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Jun 25 14:33:13 2017 Sylvain Chaugny
** Last update Fri Jun 30 19:01:35 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_CWRAPPER_HPP_
# define		CPP_ZAPPY_CWRAPPER_HPP_

# include		<string>

namespace		zappy
{
  namespace		utl
  {
    class		CWrapper
    {
    public:
      CWrapper() {}
      virtual ~CWrapper() {}

      static const char	*strerror();
      static int	close(int fd);
      static int	write(int fd, const void *msg, int size);
      static int	read(int fd, void *buf, int size);
      static void	*memset(void *s, int c, size_t n);
      static void	usleep(double delay);
    };
  };
};

#endif			/* !CPP_ZAPPY_CWRAPPER_HPP_ */
