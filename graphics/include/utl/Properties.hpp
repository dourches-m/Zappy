/*
** Properties.hpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jun 28 22:21:55 2017 Sylvain Chaugny
// Last update Sun Jul  2 11:13:48 2017 Sylvain Chaugny
*/

#ifndef				CPP_ZAPPY_PROPERTIES_HPP_
# define			CPP_ZAPPY_PROPERTIES_HPP_

# include			<cstddef>
# include			<string>
# include			"utl/CWrapper.hpp"
# include			"protocol.h"
# include			"Map.hpp"

namespace			zappy
{
  namespace			utl
  {
    class			Properties
    {
    private:
      std::vector<t_player_infos>	_players;
      std::vector<t_egg_infos>	_eggs;
      std::vector<t_cell>	_cells;
      std::vector<Tile>		_tiles;
      t_dimensions		_dimensions;
      std::pair<bool, size_t>	_init_frame;
      std::string		_broadcast_msg;
      t_position		_incantation_pos;
      std::vector<t_player_infos>	_incantation_players;
      std::vector<t_team_infos>	_teams;
      std::vector<int>		_dead_players;
      std::map<int, t_position>		_dead_positions;
      std::pair<int, enum e_player_direction> _direction;

      size_t			_frame;

    public:
      Properties() {}
      virtual ~Properties() {}

      void			clear()
      {
	_players.clear();
	_eggs.clear();
	_cells.clear();
	_tiles.clear();
	_teams.clear();
	_dead_players.clear();
	_dimensions.width = 0;
	_dimensions.height = 0;
	_init_frame.first = false;
	_init_frame.second = 0;;
	_broadcast_msg = "";
	_incantation_pos.x = 0;
	_incantation_pos.y = 0;
	_incantation_players.clear();
	CWrapper::memset(&_direction, 0, sizeof(_direction));
      }

      std::vector<Tile>		&getTiles() { return _tiles; }

      std::vector<t_player_infos>	&getPlayers() { return _players; }
      std::vector<t_egg_infos>	&getEggs() { return _eggs; }
      std::vector<t_cell>	&getCells() { return _cells; }
      t_dimensions		&getDimensions() { return _dimensions; }
      std::string		&getBroadcastMsg() { return _broadcast_msg; }
      t_position		&getIncantationPos() { return _incantation_pos; }
      std::vector<t_player_infos>	&getIncantationPlayers() { return _incantation_players; }
      std::pair<int, enum e_player_direction>	&getDirection() { return _direction; }
      size_t			&getInitFrame() { return _init_frame.second; }
      bool			isFrameInitialized() { return _init_frame.first; }
      size_t			getFrame() const { return _frame; }
      std::vector<t_team_infos>	&getTeams() { return _teams; }
      std::vector<int>		&getDeadPlayers() { return _dead_players; }
      std::map<int, t_position>	&getDeadPositions() { return _dead_positions; }

      void			addPlayer(t_player_infos const &add) { _players.emplace_back(add); }
      void			addEgg(t_egg_infos const &add) { _eggs.emplace_back(add); }
      void			addCell(t_cell const &add) { _cells.emplace_back(add); }
      void			addIncantationPlayer(t_player_infos const &add) { _incantation_players.emplace_back(add); }
      void			setDimensions(t_dimensions const &dim) { _dimensions = dim; }
      void			setBroadcastMsg(std::string const &msg) { _broadcast_msg = msg; }
      void			setIncantationPos(t_position const &pos) { _incantation_pos = pos; }
      void			setDirection(int id, enum e_player_direction dir) { _direction = std::make_pair(id, dir); }
      void			setInitFrame(size_t init) { _init_frame.second =init; _init_frame.first = true; }
      void			setFrame(size_t frame) { _frame = frame; }
      void			addTeam(t_team_infos const &team) { _teams.emplace_back(team); }
      void			addDeadPlayer(int id, int x, int y)
      {
	_dead_players.emplace_back(id);
	_dead_positions[id].x = x;
	_dead_positions[id].y = y;
      }
      void			removeDeadPlayer(int id)
      {
	int			i;

	i = 0;
	for (auto &&p: _dead_players)
	  {
	    if (p == id)
	      _dead_players.erase(_dead_players.begin() + i);
	    i++;
	  }
      }
    };
  };
};

#endif				/* !CPP_ZAPPY_PROPERTIES_HPP_ */
