//
// UiManager.cpp for zappy in /home/dourches/Epitech
//
// Made by Martin Dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  sam. juil. 1 17:23:34 2017 Martin Dourches
// Last update Sun Jul  2 15:38:47 2017 Sylvain Chaugny
//

#include <iostream>
#include "UiManager.hpp"
#include "Exceptions.hpp"

void	zappy::UiManager::init()
{
  sf::Font font;
  sf::View tmp(sf::FloatRect(1400 - 273, 0, 1400, 800));

  zoom = 1;
  all = true;
  cursor.x = 0;
  cursor.y = 0;
  _window.create(sf::VideoMode(WindowX, WindowY), "Zappy");
  if (!font.loadFromFile("ressources/arial.ttf"))
    throw exception::UiManagerException("This font is not available");
  _font = font;
  clear();
  viewmenu = tmp;
  viewmenu.move(-1125, 0);
  viewmenu.setViewport(sf::FloatRect(0, 0, 1, 0.873));
  viewmap.setCenter(345, 245);
  viewmap.setSize(700, 500);
  viewmap.zoom(zoom);
  viewmap.setViewport(sf::FloatRect(0, 0, 0.8, 0.8));
}

zappy::Map &zappy::UiManager::getMap()
{
  return map;
}

void zappy::UiManager::SoundManager()
{
  if (!_music.openFromFile("ressources/OpFF.wav"))
    throw exception::UiManagerException("Couldn't load file");
  _music.setLoop(true);
  _music.play();
}

void	zappy::UiManager::clear()
{
  _window.clear(sf::Color::Black);
}

void	zappy::UiManager::display()
{
  _window.display();
}

void	zappy::UiManager::stop()
{
  _window.close();
}

void	zappy::UiManager::loadTexture(TextureID id, std::string const &file)
{
  sf::Texture *tex = new sf::Texture();

  if (!tex->loadFromFile(file))
    throw exception::UiManagerException("Couldn't load texture");
  _tabTexture[id] = tex;
}

void	zappy::UiManager::drawSprite(float x, float y, TextureID id, float scale)
{
  sf::Sprite sprite;
  double ratio = 50 * 0.75;

  _window.setView(viewmap);
  if (!_tabTexture.empty())
    {
      sprite.setTexture(*(_tabTexture[id]));
      sprite.setScale(scale, scale);
      sprite.setPosition(x * ratio, y * ratio);
      _window.draw(sprite);
    }
  _window.setView(_window.getDefaultView());
}

void	zappy::UiManager::drawMap()
{
  _window.setView(viewmap);
  sf::Sprite sprite;
  sf::Sprite sprite2;
  double ratio = 50 * 0.75;
  sf::RectangleShape rectangle(sf::Vector2f(ratio, ratio));
  sf::Sprite spritefood;
  sf::Sprite spritephiras;
  sf::Sprite spritederaumere;
  sf::Sprite spritemendiane;
  sf::Sprite spritelinemate;
  sf::Sprite spritesibur;
  sf::Sprite spritethystame;

  spritederaumere.setTexture(*(_tabTexture[DERAUMERE]));
  spritefood.setTexture(*(_tabTexture[FOOD]));
  spritelinemate.setTexture(*(_tabTexture[LINEMATE]));
  spritemendiane.setTexture(*(_tabTexture[MENDIANE]));
  spritethystame.setTexture(*(_tabTexture[THYSTAME]));
  spritesibur.setTexture(*(_tabTexture[SIBUR]));
  spritephiras.setTexture(*(_tabTexture[PHIRAS]));
  sprite2.setTexture(*(_tabTexture[GRASS_2]));
  sprite.setTexture(*(_tabTexture[GRASS_1]));
  sprite.setScale(0.75, 0.75);
  sprite2.setScale(0.75, 0.75);
  rectangle.setOutlineThickness(1);
  for (int y = 0; y < map.getYMax(); y++)
    {
      for (int x = 0; x < map.getXMax() ;x++)
	{
	  if (map.getTile(x, y).tex == GRASS_2)
	    {
	      sprite2.setPosition(x * ratio , y * ratio);
	      _window.draw(sprite2);
	    }
	  else
	    {
	      sprite.setPosition(x * ratio, y * ratio);
	      _window.draw(sprite);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_DERAUMERE] > 0)
	    {
	      spritederaumere.setScale(0.25, 0.25);
	      spritederaumere.setPosition(x * ratio + 30, y * ratio + 30);
	      _window.draw(spritederaumere);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_SIBUR] > 0)
	    {
	      spritesibur.setScale(0.25, 0.25);
	      spritesibur.setPosition(x * ratio, y * ratio);
	      _window.draw(spritesibur);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_PHIRAS] > 0)
	    {
	      spritephiras.setScale(0.25, 0.25);
	      spritephiras.setPosition(x * ratio, y * ratio + 10);
	      _window.draw(spritephiras);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_THYSTAME] > 0)
	    {
	      spritethystame.setScale(0.25, 0.25);
	      spritethystame.setPosition(x * ratio + 10, y * ratio + 30);
	      _window.draw(spritethystame);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_FOOD] > 0)
	    {
	      spritefood.setScale(0.25, 0.25);
	      spritefood.setPosition(x * ratio +30, y * ratio + 10);
	      _window.draw(spritefood);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_MENDIANE] > 0)
	    {
	      spritemendiane.setScale(0.25, 0.25);
	      spritemendiane.setPosition(x * ratio, y * ratio + 20);
	      _window.draw(spritemendiane);
	    }
	  if (map.getTile(x, y).cell.ressources[E_RESSOURCE_LINEMATE] > 0)
	    {
	      spritelinemate.setScale(0.25, 0.25);
	      spritelinemate.setPosition(x * ratio + 20, y * ratio);
	      _window.draw(spritelinemate);
	    }
	}
    }
  rectangle.setPosition(cursor.x * ratio,
                        cursor.y * ratio);
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setFillColor(sf::Color(255, 0, 0, 70));
  _window.draw(rectangle);
  _window.setView(_window.getDefaultView());
}

void	zappy::UiManager::drawMenuPlayer()
{
  sf::RectangleShape rectangle(sf::Vector2f(WindowX * 0.1953125, WindowY));
  sf::RectangleShape rectangle2(sf::Vector2f(WindowX * 0.1953125, 125));
  sf::Text text;
  int	x;
  sf::Sprite spritefood;
  sf::Sprite spritephiras;
  sf::Sprite spritederaumere;
  sf::Sprite spritemendiane;
  sf::Sprite spritelinemate;
  sf::Sprite spritesibur;
  sf::Sprite spritethystame;
  bool teamtext;

  spritederaumere.setTexture(*(_tabTexture[DERAUMERE]));
  spritefood.setTexture(*(_tabTexture[FOOD]));
  spritelinemate.setTexture(*(_tabTexture[LINEMATE]));
  spritemendiane.setTexture(*(_tabTexture[MENDIANE]));
  spritethystame.setTexture(*(_tabTexture[THYSTAME]));
  spritesibur.setTexture(*(_tabTexture[SIBUR]));
  spritephiras.setTexture(*(_tabTexture[PHIRAS]));
  x = 0;
  rectangle2.move(WindowX * 0.8046875, 875);
  rectangle.move(WindowX * 0.8046875, 0);
  rectangle2.setOutlineColor(sf::Color::Black);
  rectangle2.setFillColor(sf::Color(51,153,255));
  rectangle2.setOutlineThickness(2);
  rectangle.setFillColor(sf::Color(51,153,255));
  rectangle.setOutlineThickness(2);
  rectangle.setOutlineColor(sf::Color::Black);
  _window.draw(rectangle2);
  rectangle2.setSize(sf::Vector2f((WindowX * 0.1953125) / 2, 125));
  _window.draw(rectangle2);
  text.setFont(_font);
  text.setColor(sf::Color::Black);
  text.setString("All");
  text.setPosition(1170, 920);
  _window.draw(text);
  text.setString("Tile");
  text.setPosition(1310, 920);
  _window.draw(text);
  _window.setView(viewmenu);
  rectangle.setSize(sf::Vector2f(WindowX * 0.1953125,
				 WindowY + (280 * map.getTile
					 (cursor.x, cursor.y).players.size())));
  _window.draw(rectangle);
      for (auto i : map.getTeams())
	{
	  teamtext = false;
	  for (std::vector<t_player_infos>::iterator it =
		  map.getPlayersByTeam(i.team_id).begin();
	       it != map.getPlayersByTeam(i.team_id).end(); it++)
	    {
	      if ((!all && it->pos.x == cursor.x && it->pos.y == cursor.y)
		  | all)
		{
		  if ((i.free_slots < i.max_slots) && !teamtext)
		    {
		      text.setCharacterSize(20);
		      text.setString(i.name);
		      text.setPosition(1220, WindowY * (1 / 60) + (x * 300));
		      _window.draw(text);
		      teamtext = true;
		    }
		  text.setCharacterSize(20);
		  rectangle.setFillColor(sf::Color::Transparent);
		  rectangle.setSize(sf::Vector2f(200, 265));
		  rectangle.setPosition(1150, +(280 * x) + 50);
		  _window.draw(rectangle);
		  text.setString("Player id:");
		  text.setPosition(1150, WindowY * (1 / 60) + 50 + (280 * x));
		  _window.draw(text);
		  text.setString(std::to_string(it->id));
		  text.setPosition(1280,
				   WindowY * (1 / 60) + 50 + (280 * x));
		  _window.draw(text);
		  text.setString("Player Level ");
		  text.setPosition(1150,
				   WindowY * (1 / 60) + 80 + (280 * x));
		  _window.draw(text);
		  text.setString(std::to_string(it->level));
		  text.setPosition(1280,
				 WindowY * (1 / 60) + 80 + (280 * x));
		  _window.draw(text);
		  spritefood.setPosition(1155, WindowY * (1 / 60) + 110 + (280 * x));
		  _window.draw(spritefood);
		  text.setString(" x");
		  text.setPosition(1185, WindowY * (1 / 60) + 110 + (280 * x));
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + 110 + (280 * x));
		  text.setString(std::to_string(
			it->inventory.ressources[E_RESSOURCE_FOOD]));
		  _window.draw(text);
		  spritelinemate.setPosition(1160,
					   WindowY * (1 / 60) + (280 * x) + 140);
		  _window.draw(spritelinemate);
		  text.setString(" x");
		  text.setPosition(1185,
				 WindowY * (1 / 60) + (280 * x) + 140);
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + (280 * x) + 140);
		  text.setString(std::to_string(
			it->inventory.ressources[E_RESSOURCE_LINEMATE]));
		  _window.draw(text);
		  spritesibur.setPosition(1160, WindowY * (1 / 60) + (280 * x)
						+ 170);
		  _window.draw(spritesibur);
		  text.setString(" x");
		  text.setPosition(1185, WindowY * (1 / 60) + (280 * x) + 170);
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + (280 * x) + 170);
		  text.setString(std::to_string(
			it->inventory.ressources[E_RESSOURCE_SIBUR]));
		  _window.draw(text);
		  spritephiras.setPosition(1160, WindowY * (1 / 60) + (280 * x) + 200);
		  _window.draw(spritephiras);
		  text.setString(" x");
		  text.setPosition(1185, WindowY * (1 / 60) + (280 * x) + 200);
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + (280 * x) + 200);
		  text.setString(std::to_string(
			it->inventory.ressources[E_RESSOURCE_PHIRAS]));
		  _window.draw(text);
		  spritederaumere.setPosition(1160, WindowY * (1 / 60) + (280 * x) + 230);
		  _window.draw(spritederaumere);
		  text.setString(" x");
		  text.setPosition(1185, WindowY * (1 / 60) + (280 * x) + 230);
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + (280 * x) + 230);
		  text.setString(std::to_string(
			it->inventory.ressources[E_RESSOURCE_DERAUMERE]));
		  _window.draw(text);
		  spritethystame.setPosition(1160, WindowY * (1 / 60) + (280 * x) + 260);
		  _window.draw(spritethystame);
		  text.setString(" x");
		  text.setPosition(1185, WindowY * (1 / 60) + (280 * x) + 260);
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + (280 * x) + 260);
		  text.setString(std::to_string(
			it->inventory.ressources[E_RESSOURCE_THYSTAME]));
		  _window.draw(text);
		  spritemendiane.setPosition(1160, WindowY * (1 / 60) + (280 * x) + 290);
		  _window.draw(spritemendiane);
		  text.setString(" x");
		  text.setPosition(1185, WindowY * (1 / 60) + (280 * x) + 290);
		  _window.draw(text);
		  text.setPosition(1210, WindowY * (1 / 60) + (280 * x) + 290);
		  text.setString(std::to_string(
			  it->inventory.ressources[E_RESSOURCE_MENDIANE]));
		  _window.draw(text);
		  x++;
	      }
	    }
	}
  _window.setView(_window.getDefaultView());
}

void	zappy::UiManager::drawMenuItem()
{
  sf::RectangleShape rectangle(sf::Vector2f(WindowX * 11.24 / 14,
					    WindowY * 18 / 100));
  sf::Text text;
  sf::Sprite spritefood;
  sf::Sprite spritephiras;
  sf::Sprite spritederaumere;
  sf::Sprite spritemendiane;
  sf::Sprite spritelinemate;
  sf::Sprite spritesibur;
  sf::Sprite spritethystame;


  spritederaumere.setTexture(*(_tabTexture[DERAUMERE]));
  spritefood.setTexture(*(_tabTexture[FOOD]));
  spritelinemate.setTexture(*(_tabTexture[LINEMATE]));
  spritemendiane.setTexture(*(_tabTexture[MENDIANE]));
  spritethystame.setTexture(*(_tabTexture[THYSTAME]));
  spritesibur.setTexture(*(_tabTexture[SIBUR]));
  spritephiras.setTexture(*(_tabTexture[PHIRAS]));
  rectangle.move(0, WindowY * 82 / 100);
  rectangle.setFillColor(sf::Color(51,153,255));
  rectangle.setOutlineThickness(2);
  rectangle.setOutlineColor(sf::Color::Black);
  _window.draw(rectangle);
  rectangle.setSize(sf::Vector2f(WindowX * 0.10714285714, WindowY * 0.17857142857));
  rectangle.setFillColor(sf::Color::Transparent);
  rectangle.setOutlineColor(sf::Color::Black);
  rectangle.setOutlineThickness(2);
  _window.draw(rectangle);
  text.setFont(_font);
  text.setColor(sf::Color::Black);
  text.setString("x = ");
  text.setPosition(WindowX * 0.0146484375, WindowY * 0.89285714285);
  _window.draw(text);
  text.setString(std::to_string(cursor.x + 1));
  text.setPosition(WindowX * 0.068359375, WindowY * 0.89285714285);
  _window.draw(text);
  text.setString("y = ");
  text.setPosition(WindowX * 0.0146484375, WindowY * 730 / 768);
  _window.draw(text);
  text.setString(std::to_string(cursor.y + 1));
  text.setPosition(WindowX * 0.068359375, WindowY * 730 / 768);
  _window.draw(text);
  spritefood.setPosition(160, WindowY * 874 / 1000);
  _window.draw(spritefood);
  text.setCharacterSize(25);
  text.setString("food :");
  text.setPosition(WindowX * 1 / 7, WindowY * 87 / 100);
  _window.draw(text);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_FOOD]));
  text.setPosition(WindowX * 3 / 14, WindowY * 874 / 1000 );
  _window.draw(text);
  spritephiras.setPosition(160, WindowY * 912 / 1000);
  spritephiras.setScale(1.25, 1.25);
  _window.draw(spritephiras);
  text.setPosition(WindowX * 1 / 7, WindowY * 91 / 100);
  text.setString("phiras :");
  _window.draw(text);
  text.setPosition(WindowX * 3 / 14, WindowY * 912 / 1000);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_PHIRAS]));
  _window.draw(text);
  spritelinemate.setPosition(160, WindowY * 95 / 100);
  spritelinemate.setScale(1.25, 1.25);
  _window.draw(spritelinemate);
  text.setPosition(WindowX * 1/ 7, WindowY * 95 / 100);
  text.setString("linemate :");
  _window.draw(text);
  text.setPosition(WindowX * 33 / 140, WindowY * 952 / 1000);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_LINEMATE]));
  _window.draw(text);
  spritederaumere.setPosition(410, WindowY * 87 / 100);
  spritederaumere.setScale(1.5, 1.25);
  _window.draw(spritederaumere);
  text.setPosition(WindowX * 45 / 140, WindowY * 87 / 100);
  text.setString("deraumere :");
  _window.draw(text);
  text.setPosition(WindowX * 62 / 140, WindowY * 87 / 100);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_DERAUMERE]));
  _window.draw(text);
  spritethystame.setPosition(410 ,WindowY * 91 / 100);
  spritethystame.setScale(1.5, 1.5);
  _window.draw(spritethystame);
  text.setPosition(WindowX * 45 / 140, WindowY * 91 / 100);
  text.setString("thystame :");
  _window.draw(text);
  text.setPosition(WindowX * 6 / 14, WindowY *  91 / 100);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_THYSTAME]));
  _window.draw(text);
  spritesibur.setPosition(410, WindowY * 95 / 100);
  spritesibur.setScale(1.5, 1.5);
  _window.draw(spritesibur);
  text.setPosition(WindowX * 45 / 140, WindowY * 95 / 100);
  text.setString("sibur :");
  _window.draw(text);
  text.setPosition(WindowX * 56 / 140, WindowY * 95 / 100);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_SIBUR]));
  _window.draw(text);
  spritemendiane.setPosition(720 ,WindowY * 87 / 100);
  spritemendiane.setScale(1.5, 1.5);
  _window.draw(spritemendiane);
 text.setPosition(WindowX * 78 / 140, WindowY * 87 / 100);
  text.setString("mendiane :");
  _window.draw(text);
 text.setPosition(WindowX * 94 / 140, WindowY * 87 / 100);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).cell
					.ressources[E_RESSOURCE_MENDIANE]));
  _window.draw(text);
  text.setPosition(WindowX * 78 / 140, WindowY * 95 / 100);
  text.setString("eggs :");
  _window.draw(text);
  text.setPosition(WindowX * 9 / 14, WindowY * 952 / 1000);
  text.setString(std::to_string(map.getTile(cursor.x, cursor.y).eggs.size()));
  _window.draw(text);
}

void	zappy::UiManager::setSpriteSheet(std::string const &path)
{
  sf::Image	spritesheet;
  sf::Texture	*texture;
  sf::Vector2u   tmp;

  if (!spritesheet.loadFromFile(path))
    throw exception::UiManagerException("Couldn't load spritesheet");
  tmp = spritesheet.getSize();
  for (size_t x = 0; x < 123; x++)
    {
      texture = new sf::Texture;
      texture->loadFromImage(spritesheet, sf::IntRect(x * (tmp.x / 123), 0,
						      tmp.x / 123, tmp.y));
      _tabTexture[x] = (texture);
    }
}

int	zappy::UiManager::pollEvents()
{
  while (_window.pollEvent(_event))
    {
      if (_event.type == sf::Event::KeyPressed)
	{
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    {
	      stop();
	      return (1);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	    {
	      if (cursor.y - 1 < 0)
		cursor.y = map.getYMax() - 1;
	      else
		cursor.y = (cursor.y - 1) % map.getYMax();
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	    cursor.y = (cursor.y + 1) % map.getYMax();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	    {
	      if (cursor.x - 1 < 0)
		cursor.x = map.getXMax() - 1;
	      else
		cursor.x = (cursor.x - 1) % map.getXMax();
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    cursor.x = (cursor.x + 1) % map.getXMax();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	    {
	      viewmap.zoom(0.99);
	      zoom *= 0.99;
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	    {
	      if (zoom < 2)
		{
		  viewmap.zoom(1.01);
		  zoom *= 1.01;
		}
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	    {
	      if (viewmap.getCenter().x > 0)
		viewmap.move(-10, 0);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	    {
	      if (viewmap.getCenter().x < (50 * 0.75) * getMap().getXMax())
		viewmap.move(10, 0);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	    {
	      if (viewmap.getCenter().y > 0)
		viewmap.move(0, -10);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	    {
	      if (viewmap.getCenter().y < (50 * 0.75) * getMap().getYMax())
		viewmap.move(0, 10);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
	    {
	      if ((viewmenu.getCenter().y) > 400)
		viewmenu.move(0, -10);
	    }
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
	    {
	      int x;

	      x = 0;
	      if (all)
		for (auto it : map.getTeams())
		  for (std::vector<t_player_infos>::iterator i = map
			  .getPlayersByTeam(it.team_id).begin();
		       i != map.getPlayersByTeam(it.team_id).begin(); i++)
		    x++;
	      if (!all && viewmenu.getCenter().y <
			  1000 + (map.getTile(cursor.x, cursor.y).players
					  .size() * 250 - 400))
		viewmenu.move(0, 10);
	      else if (all && viewmenu.getCenter().y < 1000 + x * 250 - 400)
		viewmenu.move(0, 10);
	    }
	}
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
	  sf::Mouse::getPosition(_window).x > 1130 &&
	  sf::Mouse::getPosition(_window).x <= 1260 &&
	  sf::Mouse::getPosition(_window).y > 800 &&
	  sf::Mouse::getPosition(_window).y <= 1000)
	all = true;
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
	  sf::Mouse::getPosition(_window).x > 1260 &&
	  sf::Mouse::getPosition(_window).x <= 1400 &&
	  sf::Mouse::getPosition(_window).y > 800 &&
	  sf::Mouse::getPosition(_window).y <= 1000)
	all = false;
    }
  return (0);
}

void		zappy::UiManager::drawPlayers()
{
  enum TextureID tex;

  for (auto &&team: map.getTeams())
    {
      for (auto &&player: map.getPlayersByTeam(team.team_id))
	{
	  tex = static_cast<enum TextureID>(map.getMove(player.id));
	  drawSprite(player.pos.x, player.pos.y, tex, PLAYERSCALE);
	}
      for (auto &&dead: map.getDeadPlayers())
	{
	  tex = static_cast<enum TextureID>(CHARACTER_DIE_3 - dead.second + 1);
	  drawSprite(map.getDeadPositions()[dead.first].x, map.getDeadPositions()[dead.first].y, tex, PLAYERSCALE);
	}
    }
}
