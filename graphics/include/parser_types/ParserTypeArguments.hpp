/*
** ParserTypeArguments.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/include/parser
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 15:00:51 2017 Sylvain Chaugny
** Last update Wed Jun 28 19:32:25 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_PARSERTYPEARGUMENTS_HPP_
# define		CPP_ZAPPY_PARSERTYPEARGUMENTS_HPP_

# include		<map>
# include		<string>
# include		"utl/Caster.hpp"

namespace		zappy
{
  namespace		parser
  {
    class		ParserTypeArguments
    {
    public:
      typedef std::map<std::string, std::string> t_args;

    private:
      const char	**_args;
      t_args		_tab;
      std::string	_err;

    public:
      ParserTypeArguments(const char **args) : _args(args) {}
      virtual ~ParserTypeArguments() {}

      int		parseArgs(const char **args);

      template<typename Key, typename Value>
      Value		getValue(Key &key)
      {
	return zappy::utl::Caster::cast<Key &, Value>(_tab[key]);
      }
    };
  };
};

#endif			/* !CPP_ZAPPY_PARSERTYPEARGUMENTS_HPP_ */
