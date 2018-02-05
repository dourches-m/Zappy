/*
** Core.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 14:40:41 2017 Sylvain Chaugny
// Last update Sun Jul  2 14:26:53 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_CORE_HPP_
# define			CPP_ZAPPY_CORE_HPP_

# include			<string>
# include			"Parser.hpp"
# include			"network/IPAddress.hpp"
# include			"network/Socket.hpp"
# include			"network/Listener.hpp"
# include			"parser_types/ParserTypeArguments.hpp"
# include			"package/PackageManager.hpp"
# include			"UiManager.hpp"
# include			"Map.hpp"

# include			"protocol.h"

namespace			zappy
{
  class				Core
  {
  public:
    typedef Parser<parser::ParserTypeArguments> t_arg_parser;

  private:
    network::IPAddress		_addr;
    int				_port;
    network::Socket		_server;
    network::Listener		_server_listener;
    package::PackageManager	_package_manager;
    UiManager			*_graphics;
    bool			_connected;
    Map				_map;

  private:
    void			connectToServer();

  public:
    Core();
    virtual ~Core();

    int				init(const char **av, const char **ae);
    void			checkForDisplay(const char **ae);
    int				loop();
    int				stop();
    void			update(bool is_first = false);
  };
};

#endif				/* !CPP_ZAPPY_CORE_HPP_ */
