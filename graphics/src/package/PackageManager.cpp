/*
** PackageManager.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Jun 26 20:01:22 2017 Sylvain Chaugny
// Last update Sun Jul  2 20:56:28 2017 Sylvain Chaugny
*/

#include		"package/PackageManager.hpp"
#include		"package/Package.hpp"
#include		"network/NetworkWrapper.hpp"
#include		"utl/TCP.hpp"
#include		"protocol.h"
#include		"utl/Caster.hpp"

int			zappy::package::PackageManager::parseFromBuffer(utl::Buffer &buffer)
{
  int			package_size;
  Package		package;

  package_size = 1;
  if (!buffer.getSize())
    return (0);
  if (!_connected && std::string(buffer.getPart(0, 8).data()).substr(0, 8) == "WELCOME\n")
    {
      buffer.clear();
      return (1);
    }
  while (buffer.getOffBegin() < buffer.getSize() && package_size)
    {
      package.clear();
      package_size = utl::Caster::cast<std::vector<char> &, uint32_t>(buffer.getPart(buffer.getOffBegin(), sizeof(uint32_t)));
      buffer.addToOffBegin(sizeof(package_size));
      package.getBuffer().addData(buffer.getPart(buffer.getOffBegin(), package_size));
      _parser.parseArgs(&package);
      _packages.push_back(package);
      buffer.addToOffBegin(package_size);
    }
  buffer.clear();
  return (0);
}

void			zappy::package::PackageManager::handlePackagesForFrame(size_t frame)
{
  int			i;

  i = 0;
  for (auto &&package: _packages)
    {
      if (package.getProps().getFrame() == frame)
	{
	  blendProps(package.getProps());
	  _packages.erase(_packages.begin() + i);
	}
      i++;
    }
}

int			zappy::package::PackageManager::blendProps(utl::Properties &new_props)
{
  bool			found;

  if (new_props.getPlayers().size())
    {
      for (auto &new_player: new_props.getPlayers())
	{
	  found = false;
	  for (auto &player: _props.getPlayers())
	    {
	      if (found == false && player.id == new_player.id)
		{
		  player.dir = new_player.dir == E_DIRECTIONS ? player.dir : new_player.dir;
		  player.team_id = new_player.team_id == -1 ? player.team_id : new_player.team_id;
		  player.level += new_player.level;
		  for (int i = E_RESSOURCE_FOOD; i < E_RESSOURCES; i++)
		    player.inventory.ressources[i] += new_player.inventory.ressources[i];
		  player.pos.x += new_player.pos.x;
		  player.pos.y += new_player.pos.y;
		  player.pos.x = player.pos.x < 0 ? 0 : player.pos.x;
		  player.pos.y = player.pos.y < 0 ? 0 : player.pos.y;
		  found = true;
		}
	    }
	  if (found == false)
	    _props.addPlayer(new_player);
	}
    }

  _props.getDeadPlayers().clear();

  if (new_props.getDeadPlayers().size())
    {
      for (auto &&dead: new_props.getDeadPlayers())
  	{
  	  int i = 0;
  	  found = false;
  	  for (auto &&p: _props.getPlayers())
  	    {
  	      if (!found && p.id == dead)
	      {
		_props.addDeadPlayer(dead, p.pos.x, p.pos.y);
		_props.getPlayers().erase(_props.getPlayers().begin() + i);
		found = true;
  		}
  	      i++;
  	    }
  	}
    }

  _props.setDirection(0, E_DIRECTION_EAST);
  _props.setDirection(new_props.getDirection().first, new_props.getDirection().second);

  if (new_props.getIncantationPlayers().size())
    {
      for (auto &&new_player: new_props.getIncantationPlayers())
	{
	  found = false;
	  for (auto &&player: _props.getIncantationPlayers())
	    {
	      if (found == false && player.id == new_player.id)
		{
		  player.level += new_player.id;
		  found = true;
		}
	    }
	  if (found == false)
	    _props.addIncantationPlayer(new_player);
	}
    }
  if (new_props.getCells().size())
    {
      for (auto &&new_cell: new_props.getCells())
	{
	  found = false;
	  if (new_cell.pos.x == -1 && new_cell.pos.y == -1)
	    {
	      for (auto &&player: _props.getPlayers())
		{
		  if (player.id == new_cell.ressources[0])
		    {
		      new_cell.pos.x = player.pos.x;
		      new_cell.pos.y = player.pos.y;
		    }
		}
	    }
	  for (auto &&cell: _props.getCells())
	    {
	      if (!found && cell.pos.x == new_cell.pos.x && cell.pos.y == new_cell.pos.y)
		{
		  found = true;
		  for (int i = E_RESSOURCE_FOOD; i < E_RESSOURCES; i++)
		    cell.ressources[i] += new_cell.ressources[i];
		}
	    }
	  if (!found)
	    _props.addCell(new_cell);
	}
    }
  if (new_props.getEggs().size())
    {
      for (auto &&new_egg: new_props.getEggs())
	{
	  found = false;
	  for (auto &&egg: _props.getEggs())
	    {
	      if (found == false && egg.id == new_egg.id)
		{
		  found = true;
		  egg.created = new_egg.created;
		  egg.pos.x += new_egg.pos.x;
		  egg.pos.y += new_egg.pos.y;
		  egg.dead = new_egg.dead;
		}
	    }
	  if (found == false)
	    _props.addEgg(new_egg);
	}
    }

  if (new_props.getTeams().size())
    {
      for (auto &&team: new_props.getTeams())
	_props.addTeam(team);
    }

  if (!new_props.isFrameInitialized())
    _props.setInitFrame(new_props.getInitFrame());
  if (new_props.getDimensions().height && new_props.getDimensions().width)
    _props.setDimensions(new_props.getDimensions());
  return 0;
}

int			zappy::package::PackageManager::handlePackageData(utl::Buffer &buffer)
{
  int			package_size;
  Package		package;

  package_size = 1;
  if (!buffer.getSize())
    return (0);
  while (buffer.getOffBegin() < buffer.getSize() && package_size)
    {
      package.clear();
      package_size = utl::Caster::cast<std::vector<char> &, uint32_t>(buffer.getPart(buffer.getOffBegin(), sizeof(uint32_t)));
      buffer.addToOffBegin(sizeof(package_size));
      package.getBuffer().addData(buffer.getPart(buffer.getOffBegin(), package_size));
      _parser.parseArgs(&package);
      if (package.getCmd() == E_CMD_DATA)
	{
	  blendProps(package.getProps());
	  buffer.addToOffBegin(package_size);
	  return 1;
	}
      buffer.addToOffBegin(package_size);
    }
  buffer.clear();
  return (0);
}
