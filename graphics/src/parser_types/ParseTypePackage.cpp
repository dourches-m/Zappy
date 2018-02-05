/*
** ParseTypePackage.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Jun 26 20:03:57 2017 Sylvain Chaugny
// Last update Sun Jul  2 20:03:04 2017 Sylvain Chaugny
*/

#include		<cstring>
#include		"parser_types/ParserTypePackage.hpp"
#include		"utl/Caster.hpp"
#include		"utl/CWrapper.hpp"
#include		"protocol.h"

int			zappy::parser::ParserTypePackage::parseArgs(package::Package *args)
{
  enum e_protocol_cmd	type;

  if (_args && _args != args)
    _args = args;
  type = static_cast<enum e_protocol_cmd>(utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(enum e_protocol_cmd))));
  _args->getBuffer().addToOffBegin(sizeof(enum e_protocol_cmd));
  _args->setCmd(type);
  switch (type)
    {
    case (E_CMD_PLAYER)		: return parsePackagePlayer();
    case (E_CMD_INCANTATION)	: return parsePackageIncantation();
    case (E_CMD_EGG)		: return parsePackageEgg();
    case (E_CMD_SERVER)		: return parsePackageServer();
    case (E_CMD_DATA)		: return parsePackageData();
    default			: return 1;
    };
 return 0;
}

int			zappy::parser::ParserTypePackage::parsePackagePlayer()
{
  t_protocol_player	proto;
  t_player_infos		player;
  t_egg_infos			egg;

  utl::CWrapper::memset(&player, 0, sizeof(player));
  utl::CWrapper::memset(&player.inventory, 0, sizeof(t_inventory));
  utl::CWrapper::memset(&egg, 0, sizeof(egg));
  utl::CWrapper::memset(&proto, 0, sizeof(proto));

  proto = utl::Caster::cast<std::vector<char> &, t_protocol_player>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_protocol_player)));
  _args->getBuffer().addToOffBegin(sizeof(t_protocol_player));
  _args->getProps().setFrame(proto.frame);
  player.id = proto.player_id;
  player.team_id = -1;
  player.dir = E_DIRECTIONS;
  if (!player.id)
    return 1;
  switch (proto.action)
    {
    case (E_PLAYER_NEW):
      {
	player = utl::Caster::cast<std::vector<char> &, t_player_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_player_infos)));
	if (player.id != proto.player_id)
	  return 1;
	_args->getProps().addPlayer(player);
	break;
      }

    case (E_PLAYER_MOVE):
      {
	enum e_player_direction dir;

	dir = static_cast<enum e_player_direction>(utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(enum e_player_direction))));
	player.pos.x = 0;
	player.pos.y = 0;
	player.team_id = -1;
	switch (dir)
	  {
	  case (E_DIRECTION_NORTH): player.pos.y = -1; break;
	  case (E_DIRECTION_SOUTH): player.pos.y = 1; break;
	  case (E_DIRECTION_EAST): player.pos.x = 1; break;
	  case (E_DIRECTION_WEST): player.pos.x = -1; break;
	  default: return 1;
	  }
	player.dir = dir;
	_args->getProps().setDirection(player.id, dir);
	_args->getProps().addPlayer(player);
	break;
      }

    case (E_PLAYER_EXPULSE):
      {
	break;
      }

    case (E_PLAYER_BROADCAST):
      {
	std::string msg(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), _args->getSize() - _args->getBuffer().getOffBegin()).data());
	_args->getProps().setBroadcastMsg(msg);
	break;
      }

    case (E_PLAYER_FORK):
      {
	egg = utl::Caster::cast<std::vector<char> &, t_egg_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_egg_infos)));
	_args->getProps().addEgg(egg);
	break;
      }

    case (E_PLAYER_DELETE_RESSOURCE):
      {
	enum e_ressources ressource;

	ressource = static_cast<enum e_ressources>(utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(enum e_ressources))));
	player.inventory.ressources[ressource] = -1;
	_args->getProps().addPlayer(player);
	break;
      }

    case (E_PLAYER_GET_RESSOURCE):
      {
	enum e_ressources ressource;
	t_cell		cell;

	utl::CWrapper::memset(&cell, 0, sizeof(cell));
	ressource = static_cast<enum e_ressources>(utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(enum e_ressources))));
	player.inventory.ressources[ressource] = 1;

	utl::CWrapper::memset(&cell, 0, sizeof(cell));

	cell.pos.x = -1;
	cell.pos.y = -1;
	cell.ressources[0] = player.id;
	cell.ressources[ressource] = -1;
	_args->getProps().addCell(cell);
	_args->getProps().addPlayer(player);
	break;
      }

    case (E_PLAYER_DIE):
      {
	_args->getProps().addDeadPlayer(player.id, 0, 0);
	break;
      }

    case (E_PLAYER_NEW_FOR_EGG):
      {
	break;
      }
    default: return 1;
    };
  return 0;
}

int				zappy::parser::ParserTypePackage::parsePackageIncantation()
{
  t_protocol_incantation	proto;
  t_position			pos;
  t_player_infos		player;
  t_player_infos		player_tmp;
  int				res;

  utl::CWrapper::memset(&player, 0, sizeof(player));
  utl::CWrapper::memset(&player_tmp, 0, sizeof(player_tmp));
  proto = utl::Caster::cast<std::vector<char> &, t_protocol_incantation>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_protocol_incantation)));
  _args->getBuffer().addToOffBegin(sizeof(t_protocol_incantation));
  _args->getProps().setFrame(proto.frame);
  switch (proto.action)
    {
    case (E_INCANTATION_BEGIN):
      {
	pos = utl::Caster::cast<std::vector<char> &, t_position>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_position)));
	_args->getBuffer().addToOffBegin(sizeof(t_position));
	_args->getProps().setIncantationPos(pos);
	while (_args->getBuffer().getOffBegin() < _args->getSize())
	  {
	    player_tmp = utl::Caster::cast<std::vector<char> &, t_player_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_player_infos)));
	    player.id = player_tmp.id;
	    _args->getBuffer().addToOffBegin(sizeof(t_player_infos));
	    _args->getProps().addIncantationPlayer(player);
	  }
	break;
      }

    case (E_INCANTATION_END):
      {
	res = utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(int32_t)));
	_args->getBuffer().addToOffBegin(sizeof(int));
	if (res == 1)
	  {
	    while (_args->getBuffer().getOffBegin() < _args->getSize())
	      {
		player_tmp = utl::Caster::cast<std::vector<char> &, t_player_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_player_infos)));
		player.id = player_tmp.id;
		player.level = 1;
		_args->getBuffer().addToOffBegin(sizeof(t_player_infos));
		_args->getProps().addIncantationPlayer(player);
	      }
	  }
	break;
      }

    default: return 1;
    }
  return 0;
}

int			zappy::parser::ParserTypePackage::parsePackageEgg()
{
  t_protocol_egg	proto;
  t_egg_infos			egg;
  int			id;

  utl::CWrapper::memset(&egg, 0, sizeof(egg));
  proto = utl::Caster::cast<std::vector<char> &, t_protocol_egg>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_protocol_egg)));
  _args->getBuffer().addToOffBegin(sizeof(t_protocol_egg));
  _args->getProps().setFrame(proto.frame);
  switch (proto.action)
    {
    case (E_EGG_HATCH):
      {
	id = utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(egg.id)));
	egg.created = true;
	egg.id = id;
	_args->getProps().addEgg(egg);
	break;
      }
    case (E_EGG_DIE):
      {
	id = utl::Caster::cast<std::vector<char> &, int32_t>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(egg.id)));
	egg.id = id;
	egg.dead = true;
	_args->getProps().addEgg(egg);
	break;
      }
    default: return 1;
    }
  return 0;
}

int			zappy::parser::ParserTypePackage::parsePackageServer()
{
  t_protocol_server	proto;

  proto = utl::Caster::cast<std::vector<char> &, t_protocol_server>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_protocol_server)));
  _args->getProps().setFrame(proto.frame);
  return 0;
}

int			zappy::parser::ParserTypePackage::parsePackageData()
{
  t_protocol_data	proto;
  t_cell		cell;
  t_player_infos	        player;
  t_egg_infos		        egg;
  t_team_infos		team;

  proto = utl::Caster::cast<std::vector<char> &, t_protocol_data>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_protocol_data)));
  _args->getProps().setDimensions(proto.dimensions);
  _args->getProps().setInitFrame(proto.init_frame);
  _args->getBuffer().addToOffBegin(sizeof(t_protocol_data));

  for (int i = 0; i < proto.dimensions.width * proto.dimensions.height; i++)
    {
      cell = utl::Caster::cast<std::vector<char> &, t_cell>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_cell)));
      _args->getBuffer().addToOffBegin(sizeof(t_cell));
      _args->getProps().addCell(cell);
    }

  for (int i = 0; i < proto.nb_player; i++)
    {
      player = utl::Caster::cast<std::vector<char> &, t_player_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_player_infos)));
      _args->getBuffer().addToOffBegin(sizeof(t_player_infos));
      _args->getProps().addPlayer(player);
    }

  for (int i = 0; i < proto.nb_egg; i++)
    {
      egg = utl::Caster::cast<std::vector<char> &, t_egg_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_egg_infos)));
      _args->getBuffer().addToOffBegin(sizeof(t_egg_infos));
      _args->getProps().addEgg(egg);
    }

  for (int i = 0; i < proto.nb_team; i++)
    {
      team = utl::Caster::cast<std::vector<char> &, t_team_infos>(_args->getBuffer().getPart(_args->getBuffer().getOffBegin(), sizeof(t_team_infos)));
      _args->getBuffer().addToOffBegin(sizeof(t_team_infos));
      _args->getProps().addTeam(team);
    }
  return 0;
}
