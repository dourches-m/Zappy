/*
** Core.cpp for zappy in /home/sylvain/Documents/projets/tek2/PSU/PSU_2016_zappy/graphic_client
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Jun 22 14:43:57 2017 Sylvain Chaugny
// Last update Sun Jul  2 20:59:13 2017 Sylvain Chaugny
*/

#include		<fcntl.h>
#include		<iostream>
#include		"Core.hpp"
#include		"Exceptions.hpp"
#include		"utl/Timer.hpp"
#include		"network/NetworkWrapper.hpp"

zappy::Core::Core() :
  _addr(),
  _port(0),
  _server(),
  _graphics(nullptr),
  _connected(false)
{
}

zappy::Core::~Core()
{
  if (_graphics)
    delete _graphics;
}

void			zappy::Core::checkForDisplay(const char **ae)
{
  std::string		s;
  bool			found;

  found = false;
  if (!ae)
    throw exception::UiManagerException("Couldn't find DISPLAY environment variable");
  for (int i = 0; ae[i]; i++)
    {
      s = std::string(ae[i]);
      if (!found && s.length() > 8 && s.substr(0, 8) == "DISPLAY=")
	found = true;
    }
  if (!found)
    throw exception::UiManagerException("Couldn't find DISPLAY environment variable");
}

int			zappy::Core::init(const char **av, const char **ae)
{
  t_arg_parser		args_parser;

  args_parser.parseArgs(av);
  if (args_parser.getValue<std::string, int>("-p", _port) ||
      args_parser.getValue<std::string, network::IPAddress>("-h", _addr))
    return 1;
  utl::Log::log("Initializing graphical client");
  try
    {
      checkForDisplay(ae);
      _graphics = new UiManager();
      _graphics->init();
      _graphics->setSpriteSheet("ressources/spritesheet.png");
      _graphics->loadTexture(UiManager::GRASS_1, "ressources/grass_1.png");
      _graphics->loadTexture(UiManager::GRASS_2, "ressources/grass_2.png");
      _graphics->loadTexture(UiManager::LINEMATE,
      			     "ressources/gems/linemate.png");
      _graphics->loadTexture(UiManager::DERAUMERE,
      			     "ressources/gems/deraumere.png");
      _graphics->loadTexture(UiManager::SIBUR,
      			     "ressources/gems/sibur.png");
      _graphics->loadTexture(UiManager::THYSTAME,
      			     "ressources/gems/thystame.png");
      _graphics->loadTexture(UiManager::MENDIANE,
      			     "ressources/gems/mendiane.png");
      _graphics->loadTexture(UiManager::PHIRAS,
      			     "ressources/gems/phiras.png");
      _graphics->loadTexture(UiManager::FOOD,
			     "ressources/padthai.png");

      _graphics->getMap().setXMax(0);
      _graphics->getMap().setYMax(0);
      _graphics->SoundManager();

      utl::Log::log("Trying to connect to the server (IP address: " + _addr.get() + ", port: " + std::to_string(_port) + ")");
      connectToServer();
      _server_listener.init(_server);
      _package_manager.init(&_server);
    }
  catch (exception::NetworkException const &e)
    {
      utl::Log::error("Network Exception: " + std::string(e.what()));
      return 1;
    }
  catch(exception::UiManagerException const &e)
    {
      utl::Log::error("UI Manager Exception: " + std::string(e.what()));
      return 1;
    }
  utl::Log::log("Connected");
  return 0;
}

void			zappy::Core::connectToServer()
{
  _server.setPort(_port);
  _server.setAddr(_addr.get());
  _server.init();
  _server.connect();
  network::NetworkWrapper::fcntl(_server.getFd(), F_SETFL, network::NetworkWrapper::fcntl(_server.getFd(), F_GETFL, 0) | O_NONBLOCK);
}

int			zappy::Core::loop()
{
  size_t		frame;
  utl::Timer		timer;
  bool			_waiting_data;

  frame = 0;
  timer.setDelay(5);
  _waiting_data = false;
  _package_manager.setConnected(false);
  while (_server_listener.isRunning() != -1)
    {
      _graphics->clear();
      if (!_waiting_data && _connected)
	{
	  if (_graphics->pollEvents() == 1)
	    return 0;
	  _graphics->drawMenuItem();
	  _graphics->drawMenuPlayer();
	  _graphics->drawMap();
	  _graphics->drawPlayers();
 	}
      _graphics->display();
      if (_server_listener.isSet())
	{
	  _server_listener.bufferize();
	  if (!_waiting_data && _package_manager.parseFromBuffer(_server_listener.getBuffer()))
	    {
	      _connected = true;
	      _waiting_data = true;
	      _package_manager.setConnected(true);
	      _server_listener.replyToWelcome();
	    }
	  else if (_waiting_data)
	    {
	      if (_package_manager.handlePackageData(_server_listener.getBuffer()))
		{
		  _package_manager.parseFromBuffer(_server_listener.getBuffer());
		  frame = _package_manager.getProps().getInitFrame();
		  _waiting_data = false;
		  _graphics->getMap().setXMax(_package_manager.getProps().getDimensions().width);
		  _graphics->getMap().setYMax(_package_manager.getProps().getDimensions().height);
		  update(true);
		}
	    }
	}
      if (_connected && !_waiting_data)
	_package_manager.handlePackagesForFrame(frame);
      if (timer.isAllowed())
	{
	  update();
	  frame += _connected ? 1 : 0;
	}
    }
  return 0;
}

int			zappy::Core::stop()
{
  _server.close();
  return 0;
}

void			zappy::Core::update(bool is_first)
{
  std::vector<t_player_infos>	tmp_p;
  std::vector<t_egg_infos>	tmp_e;
  Tile			tile;

  for (auto &&team: _graphics->getMap().getTeams())
    {
      for (auto &&player: _graphics->getMap().getPlayersByTeam(team.team_id))
	_graphics->getMap().updateMove(player);
    }
  _graphics->getMap().updateDeadPlayers();
  _graphics->getMap().clear();
  for (auto &&cell: _package_manager.getProps().getCells())
    {
      tmp_p.clear();
      tmp_e.clear();
      for (auto &&player: _package_manager.getProps().getPlayers())
	{
	  if (player.pos.x == cell.pos.x && player.pos.y == cell.pos.y)
	    tmp_p.emplace_back(player);
	}
      for (auto &&egg: _package_manager.getProps().getEggs())
	{
	  if (egg.pos.x == cell.pos.x && egg.pos.y == cell.pos.y)
	    tmp_e.emplace_back(egg);
	}
      tile.cell = cell;
      tile.eggs = tmp_e;
      tile.players = tmp_p;
      _graphics->getMap().addTile(cell.pos.x, cell.pos.y, tile);
    }
  if (is_first)
    {
      for (auto &&team: _package_manager.getProps().getTeams())
	_graphics->getMap().addTeam(team);
    }
  for (auto &&dead: _package_manager.getProps().getDeadPlayers())
    {
      _graphics->getMap().addDeadPlayer(dead, _package_manager.getProps().getDeadPositions()[dead].x, _package_manager.getProps().getDeadPositions()[dead].y);
    }
  _package_manager.getProps().getDeadPlayers().clear();
  for (auto &&player: _package_manager.getProps().getPlayers())
    {
      if (player.id == _package_manager.getProps().getDirection().first && _package_manager.getProps().getDirection().first)
	{
	  _package_manager.getProps().setDirection(0, _package_manager.getProps().getDirection().second);
	  _graphics->getMap().reinitMove(player);
	}
      _graphics->getMap().addPlayerToTeam(player, player.team_id);
    }

}
