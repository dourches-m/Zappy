/*
** IPAddress.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/include
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 19:46:22 2017 Sylvain Chaugny
** Last update Thu Jun 22 21:00:17 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_IPADDRESS_HPP_
# define		CPP_ZAPPY_IPADDRESS_HPP_

# include		<string>

namespace		zappy
{
  namespace		network
  {
    class		IPAddress
    {
    private:
      std::string	_raw;
      std::string	_addr;

    public:
      IPAddress(std::string const &str = "");
      IPAddress(IPAddress const &ref) : _raw(ref._raw), _addr(ref._addr) {}
      IPAddress const	&operator=(IPAddress const &ref);
      virtual ~IPAddress();

      void		setRawAddr(std::string const &raw);
      int	        load();
      std::string const	&get();
    };
  };
};

#endif			/* !CPP_ZAPPY_IPADDRESS_HPP_ */
