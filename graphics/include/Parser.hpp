/*
** Parser.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client/src
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 14:54:46 2017 Sylvain Chaugny
** Last update Mon Jun 26 20:28:52 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_PARSER_HPP_
# define		CPP_ZAPPY_PARSER_HPP_

# include		<exception>
# include		"utl/Log.hpp"

namespace		zappy
{
  template<typename ParserType>
  class			Parser
  {
  private:
    ParserType		*_parser_type;

  public:
    Parser() : _parser_type(nullptr) {}
    virtual ~Parser()
    {
      if (_parser_type != nullptr)
	delete _parser_type;
    }

    template<typename Args>
    int		parseArgs(Args const &args)
    {
      if (_parser_type == nullptr)
	_parser_type = new ParserType(args);
      try
	{
	  return _parser_type->parseArgs(args);
	}
      catch (std::exception const &e)
	{
	  utl::Log::error("Parsing Exception: " + std::string(e.what()));
	  return 1;
	}
    }

    template<typename Key, typename Value>
    int		getValue(Key &&key, Value &data)
    {
      try
	{
	  data = _parser_type->template getValue<Key, Value>(key);
	}
      catch (...)
	{
	  utl::Log::error("Parsing Exception: Unknown key or bad argument type");
	  return 1;
	}
      return 0;
    }
  };
};

#endif			/* !CPP_ZAPPY_PARSER_HPP_ */
