/*
** ParserTypePackage.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Jun 26 17:30:10 2017 Sylvain Chaugny
// Last update Sat Jul  1 23:10:29 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_PARSERTYPEPACKAGE_HPP_
# define		CPP_ZAPPY_PARSERTYPEPACKAGE_HPP_

# include		<map>
# include		<string>
# include		"package/Package.hpp"

namespace		zappy
{
  namespace		parser
  {
    class		ParserTypePackage
    {
    private:
      package::Package	*_args;

    public:
      ParserTypePackage(package::Package *args) : _args(args) {}
      virtual ~ParserTypePackage() {}

      int		parseArgs(package::Package *args);

      int		parsePackagePlayer();
      int		parsePackageIncantation();
      int		parsePackageEgg();
      int		parsePackageServer();
      int		parsePackageData();
    };
  };
};

#endif			/* !CPP_ZAPPY_PARSERTYPEPACKAGE_HPP_ */
