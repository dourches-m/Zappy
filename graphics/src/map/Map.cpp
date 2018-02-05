//
// Map.cpp for zappy in /home/dourches/Epitech
//
// Made by Martin Dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  sam. juil. 1 17:23:29 2017 Martin Dourches
// Last update Sun Jul  2 20:54:42 2017 Sylvain Chaugny
//

#include "Map.hpp"

std::vector<zappy::Tile> const& zappy::Map::getMap() const
{
  return map;
}

void zappy::Map::modTile(int x, int y, t_cell const &c, std::vector<t_egg_infos> const &e,
		  std::vector<t_player_infos> const &p)
{
  for (auto &&tile: map)
    {
      if (tile.cell.pos.x == x && tile.cell.pos.y == y)
  	{
  	  tile.cell = c;
  	  tile.eggs = e;
  	  tile.players = p;
  	}
    }
}

void zappy::Map::addTile(int, int, zappy::Tile const &t)
{
  map.emplace_back(t);
}

void zappy::Map::addTile(zappy::Tile const &t)
{
  map.push_back(t);
}

zappy::Tile &zappy::Map::getTile(int x, int y)
{
  x = x < 0 ? 0 : x;
  y = y < 0 ? 0 : y;
  return (map[x + (y * XMax)]);
}

int zappy::Map::getXMax() const
{
  return (XMax);
}

int zappy::Map::getYMax() const
{
  return (YMax);
}

void zappy::Map::setCells(std::vector<zappy::Tile> const &t)
{
  for (std::vector<zappy::Tile>::const_iterator it = t.begin(); it != t.end(); it++)
    addTile(*it);
}

std::string const &zappy::Map::getTeamNameById(int id)
{
  for (auto &&team: _teams)
    {
      if (team.team_id == id)
	{
	  _current_name = std::string(team.name);
	  return _current_name;
	}
    }
  _current_name = "";
  return _current_name;
}

void zappy::Map::clear()
{
  map.clear();
  _players_by_team.clear();
}

void zappy::Map::updateMove(t_player_infos &player)
{
  int max;

  if (player.dir == E_DIRECTION_NORTH)
    max = 3 + (player.level - 1) * 15;
  else if (player.dir == E_DIRECTION_SOUTH)
    max = 6 + (player.level - 1) * 15;
  else if (player.dir == E_DIRECTION_EAST)
    max = 9 + (player.level - 1) * 15;
  else if (player.dir == E_DIRECTION_WEST)
    max = 12 + (player.level - 1) * 15;
  _moves[player.id].second++;
  if (_moves[player.id].second >= max)
    _moves[player.id].second -= 3;
}

void zappy::Map::updateDeadPlayers()
{
  int i;

  i = 0;
  for (auto &&d: _dead_players)
    {
      d.second--;
      if (!d.second)
	_dead_players.erase(_dead_players.begin() + i);
      i++;
    }
}

void zappy::Map::addPlayerToTeam(t_player_infos const &player, int team_id)
{
  _players_by_team[team_id].emplace_back(player);
  if (!_moves[player.id].first)
    {
      _moves[player.id].first = true;
      if (player.dir == E_DIRECTION_SOUTH)
	_moves[player.id].second = (player.level - 1) * 15;
      else if (player.dir == E_DIRECTION_NORTH)
	_moves[player.id].second = 3 + (player.level - 1) * 15;
      else if (player.dir == E_DIRECTION_EAST)
	_moves[player.id].second = 6 + (player.level - 1) * 15;
      else if (player.dir == E_DIRECTION_WEST)
	_moves[player.id].second = 9 + (player.level - 1) * 15;
    }
}

void zappy::Map::reinitMove(t_player_infos const &player)
{
  if (player.dir == E_DIRECTION_SOUTH)
    _moves[player.id].second = (player.level - 1) * 15;
  else if (player.dir == E_DIRECTION_NORTH)
    _moves[player.id].second = 3 + (player.level - 1) * 15;
  else if (player.dir == E_DIRECTION_EAST)
    _moves[player.id].second = 6 + (player.level - 1) * 15;
  else if (player.dir == E_DIRECTION_WEST)
    _moves[player.id].second = 9 + (player.level - 1) * 15;
}

zappy::Tile &zappy::Map::getTileByPlayer(int id, bool &found)
{
  for (auto &tile: map)
    {
      for (auto &player: tile.players)
	{
	  if (player.id == id)
	    {
	      found = true;
	      return tile;
	    }
	}
    }
  return map[0];
}

void zappy::Map::addPlayerToTile(t_player_infos &player)
{
  for (auto &&tile: map)
    {
      if (tile.cell.pos.x == player.pos.x && tile.cell.pos.y == player.pos.y)
	{
	  tile.players.emplace_back(player);
	  return ;
	}
    }
}

void zappy::Tile::erasePlayer(int id)
{
  int i;

  i = 0;
  for (auto &&player: players)
    {
      if (player.id == id)
	{
	  players.erase(players.begin() + i);
	  return ;
	}
      i++;
    }
}

zappy::Tile &zappy::Map::getTileByPos(int x, int y, bool &found)
{
  for (auto &tile: map)
    {
      if (tile.cell.pos.x == x && tile.cell.pos.y == y)
	{
	  found = true;
	  return tile;
	}
    }
  return map[0];
}
