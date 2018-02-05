/*
** Exceptions.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 18:37:57 2017 Sylvain Chaugny
// Last update Sun Jul  2 13:37:48 2017 Sylvain Chaugny
*/

#ifndef			CPP_ZAPPY_EXCEPTIONS_HPP_
# define		CPP_ZAPPY_EXCEPTIONS_HPP_

# include		<string>
# include		<exception>

namespace		zappy
{
  namespace		exception
  {
    class		ParserTypeArgumentsException : public std::exception
    {
    private:
      std::string       _err;

    public:
      ParserTypeArgumentsException(char const *err, char const *prog = nullptr) noexcept :
	_err(std::string(err) + "\nUsage: " + std::string(prog) + " -p [port] -h [IP address]") {}
      virtual ~ParserTypeArgumentsException() noexcept {}

      virtual char const *what() const noexcept
      {
	return _err.c_str();
      }
    };

    class		NetworkException : public std::exception
    {
    private:
      std::string       _err;

    public:
      NetworkException(char const *err) noexcept :
	_err(std::string(err)) {}
      virtual ~NetworkException() noexcept {}

      virtual char const *what() const noexcept
      {
	return _err.c_str();
      }
    };

    class		UiManagerException : public std::exception
    {
    private:
      std::string       _err;

    public:
      UiManagerException(char const *err) noexcept :
	_err(std::string(err)) {}
      virtual ~UiManagerException() noexcept {}

      virtual char const *what() const noexcept
      {
	return _err.c_str();
      }
    };
  };
};

#endif			/* !CPP_ZAPPY_EXCEPTIONS_HPP_*/
