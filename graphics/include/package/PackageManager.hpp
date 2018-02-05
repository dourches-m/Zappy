/*
** PackageManager.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Jun 26 19:54:56 2017 Sylvain Chaugny
** Last update Fri Jun 30 22:43:14 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_PACKAGEMANAGER_HPP_
# define			CPP_ZAPPY_PACKAGEMANAGER_HPP_

# include			<vector>
# include			"package/Package.hpp"
# include			"Parser.hpp"
# include			"network/Socket.hpp"
# include			"parser_types/ParserTypePackage.hpp"
# include			"utl/Properties.hpp"
# include			"utl/Buffer.hpp"

namespace			zappy
{
  namespace			package
  {
    class			PackageManager
    {
    public:
      typedef Parser<parser::ParserTypePackage> t_pack_parser;

    private:
      std::vector<Package>	_packages;
      t_pack_parser		_parser;
      network::Socket		*_server;
      utl::Properties		_props;
      bool			_connected;

    public:
      PackageManager() : _packages(0) {}
      virtual ~PackageManager() {}

      void			init(network::Socket *sock) { _server = sock; }

      int			blendProps(utl::Properties &props);

      int			parseFromBuffer(utl::Buffer &buffer);
      void			handlePackagesForFrame(size_t frame);
      int			handlePackageData(utl::Buffer &buffer);

      utl::Properties		&getProps() { return _props; }
      void			setConnected(bool connected) { _connected = connected; }
    };
  };
};

#endif				/* !CPP_ZAPPY_PACKAGEMANAGER_HPP_ */
