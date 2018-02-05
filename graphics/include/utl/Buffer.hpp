/*
** Buffer.hpp for zppy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jun 30 01:49:52 2017 Sylvain Chaugny
** Last update Fri Jun 30 16:39:43 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_BUFFER_HPP_
# define			CPP_ZAPPY_BUFFER_HPP_

# include			<cstddef>
# include			<vector>

namespace			zappy
{
  namespace			utl
  {
    class			Buffer
    {
    private:
      std::vector<char>		_data;
      std::vector<char>		_part;
      size_t			_off_begin;

    public:
      Buffer();
      Buffer(Buffer const &ref);
      Buffer			&operator=(Buffer const &ref);
      virtual ~Buffer();

      void			clear();
      void			addData(std::vector<char> const &data);
      std::vector<char>		&getData();
      size_t			getSize() const { return _data.size(); }

      void			init(size_t size);
      std::vector<char>		&getPart(size_t from, size_t to);

      void			setOffBegin(size_t off) { _off_begin = off; }
      size_t			getOffBegin() const;
      void			addToOffBegin(size_t add);
    };
  };
};

#endif				/* !CPP_ZAPPY_BUFFER_HPP_ */
