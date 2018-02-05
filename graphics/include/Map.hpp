//
// Map.hpp for zappy in /home/dourches/Epitech
//
// Made by Martin Dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  sam. juil. 1 17:24:07 2017 Martin Dourches
// Last update Sun Jul  2 20:53:56 2017 Sylvain Chaugny
//


#ifndef                Map_HPP
# define                Map_HPP

# include		<string>
# include		<map>
# include		<vector>
# include		"protocol.h"

namespace		zappy
{
  struct		Tile
  {
    Tile() {};
    ~Tile() {};

    t_cell cell;
    std::vector<t_egg_infos> eggs;
    std::vector<t_player_infos> players;
    int tex;

    void erasePlayer(int id);
  };

  class			Map
  {
    std::vector<Tile> map;
    std::vector<t_team_infos> _teams;
    std::map<int, std::vector<t_player_infos>> _players_by_team;
    std::map<int, std::pair<bool, int>> _moves;
    std::vector<std::pair<int, int>> _dead_players;
    std::map<int, t_position> _dead_positions;
    std::string _current_name;
    int XMax;
    int YMax;

  public:
    Map() {};
    ~Map() {};

    std::vector<Tile> const &getMap() const;
    void	modTile(int, int, t_cell const &, std::vector<t_egg_infos> const &, std::vector<t_player_infos> const &);
    Tile &getTile(int x, int y);

    void addTile(int , int, Tile const &);
    void addTile(Tile const &);
    int getXMax() const;
    int getYMax() const;
    void setXMax(int x) { XMax = x; }
    void setYMax(int y) { YMax = y; }

    void setCells(std::vector<Tile> const &);
    std::vector<Tile> &getCells() { return map; }
    int getMove(int id) { return _moves[id].second; }
    void reinitMove(t_player_infos const &player);

    std::string const &getTeamNameById(int team_id);
    std::vector<t_team_infos> &getTeams() { return _teams; }
    std::vector<t_player_infos> &getPlayersByTeam(int team_id) { return _players_by_team[team_id]; }
    void addTeam(t_team_infos const &team) { _teams.emplace_back(team); }
    void addPlayerToTeam(t_player_infos const &player, int team_id);

    void updateMove(t_player_infos &player);
    void clear();


    Tile &getTileByPlayer(int id, bool &found);
    Tile &getTileByPos(int x, int y, bool &);

    void addPlayerToTile(t_player_infos &player);
    std::vector<Tile> &getTiles() { return map; }

    void addDeadPlayer(int id, int x, int y)
    {
      t_position pos;

      pos.x = x;
      pos.y = y;
      _dead_players.emplace_back(std::make_pair(id, 3));
      _dead_positions[id] = pos;
    }
    std::vector<std::pair<int, int>> &getDeadPlayers() { return _dead_players; }
    std::map<int, t_position> &getDeadPositions() { return _dead_positions; }
    void updateDeadPlayers();

  };
};

#endif                //Map_HPP
