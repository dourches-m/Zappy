/*
** Caster.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/include
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 15:29:47 2017 Sylvain Chaugny
** Last update Fri Jun 30 15:27:24 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_CASTER_HPP_
# define		CPP_ZAPPY_CASTER_HPP_

# include		<vector>

namespace		zappy
{
  namespace		utl
  {
    class		Caster
    {
    private:
      template<typename To>
      static To		fromVectorTo(std::vector<char> &arg)
      {
	To		*tmp;

	tmp = reinterpret_cast<To *>(arg.data());
	return *tmp;
      }

    public:
      Caster() {}
      virtual ~Caster() {}

      template<typename From, typename To>
      static To		cast(From arg);
    };
  };
};

#endif			/* !CPP_ZAPPY_CASTER_HPP_ */
