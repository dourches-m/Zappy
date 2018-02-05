/*
** Package.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Jun 26 17:35:42 2017 Sylvain Chaugny
** Last update Fri Jun 30 21:51:59 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_PACKAGE_HPP_
# define		CPP_ZAPPY_PACKAGE_HPP_

# include		<vector>
# include		"utl/Buffer.hpp"
# include		"utl/Properties.hpp"

namespace		zappy
{
  namespace		package
  {
    class		Package
    {
    private:
      size_t		_size;
      utl::Buffer	_buffer;
      utl::Properties	_props;
      enum e_protocol_cmd	_cmd;

    public:
      Package();
      Package(Package const &ref);
      Package		&operator=(Package const &ref);
      virtual ~Package();

      void		clear();
      void	        init(size_t size);
      char		*getData();
      size_t		getSize() const;
      utl::Buffer	&getBuffer() { return _buffer; }
      utl::Properties	&getProps() { return _props; }
      void		setCmd(enum e_protocol_cmd cmd) { _cmd = cmd; }
      enum e_protocol_cmd getCmd() const { return _cmd; }
    };
  };
};

#endif			/* !CPP_ZAPPY_PACKAGE_HPP_ */
