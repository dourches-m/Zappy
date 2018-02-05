/*
** Caster.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 16:31:17 2017 Sylvain Chaugny
// Last update Sun Jul  2 01:20:58 2017 Sylvain Chaugny
*/

#include			<string>
#include			"protocol.h"
#include			"utl/Caster.hpp"
#include			"network/IPAddress.hpp"

namespace			zappy
{
  namespace			utl
  {
    template<>
    int				Caster::cast<std::string &, int>(std::string &arg)
    {
      return std::stoi(arg);
    }

    template<>
    zappy::network::IPAddress	Caster::cast<std::string &, zappy::network::IPAddress>(std::string &arg)
    {
      zappy::network::IPAddress	addr(arg);

      if (addr.load())
	throw std::exception();
      return addr;
    }

    template<>
    int				Caster::cast<std::vector<char> &, int>(std::vector<char> &arg)
    { return fromVectorTo<int>(arg); }

    /*
    ** protocol_casting
    */

    template<>
    t_protocol_player		Caster::cast<std::vector<char> &, t_protocol_player>(std::vector<char> &arg)
    { return fromVectorTo<t_protocol_player>(arg); }

    template<>
    t_protocol_incantation		Caster::cast<std::vector<char> &, t_protocol_incantation>(std::vector<char> &arg)
    { return fromVectorTo<t_protocol_incantation>(arg); }

    template<>
    t_protocol_egg		Caster::cast<std::vector<char> &, t_protocol_egg>(std::vector<char> &arg)
    { return fromVectorTo<t_protocol_egg>(arg); }

    template<>
    t_protocol_server		Caster::cast<std::vector<char> &, t_protocol_server>(std::vector<char> &arg)
    { return fromVectorTo<t_protocol_server>(arg); }

    template<>
    t_protocol_data		Caster::cast<std::vector<char> &, t_protocol_data>(std::vector<char> &arg)
    { return fromVectorTo<t_protocol_data>(arg); }

    /*
    ** structures
    */

    template<>
    t_player_infos		Caster::cast<std::vector<char> &, t_player_infos>(std::vector<char> &arg)
    { return fromVectorTo<t_player_infos>(arg); }

    template<>
    t_egg_infos			Caster::cast<std::vector<char> &, t_egg_infos>(std::vector<char> &arg)
    { return fromVectorTo<t_egg_infos>(arg); }

    template<>
    t_position		Caster::cast<std::vector<char> &, t_position>(std::vector<char> &arg)
    { return fromVectorTo<t_position>(arg); }

    template<>
    t_cell		Caster::cast<std::vector<char> &, t_cell>(std::vector<char> &arg)
    { return fromVectorTo<t_cell>(arg); }

    template<>
    t_team_infos		Caster::cast<std::vector<char> &, t_team_infos>(std::vector<char> &arg)
    { return fromVectorTo<t_team_infos>(arg); }

    /*
    ** other
    */

    template<>
    uint32_t		Caster::cast<std::vector<char> &, uint32_t>(std::vector<char> &arg)
    { return fromVectorTo<uint32_t>(arg); }

    template<>
    std::string		Caster::cast<std::vector<char> &, std::string>(std::vector<char> &arg)
    { return std::string(arg.data()); }
  };
};
