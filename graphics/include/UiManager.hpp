//
// UiManager.hpp for zappy in /home/dourches/Epitech
//
// Made by Martin Dourches
// Login   <martin.dourches@epitech.eu>
//
// Started on  sam. juil. 1 17:24:18 2017 Martin Dourches
// Last update Sun Jul  2 14:07:07 2017 Sylvain Chaugny
//

#ifndef                UiManager_HPP
# define                UiManager_HPP

# include	<SFML/Window.hpp>
# include	<SFML/Graphics.hpp>
# include	<SFML/System.hpp>
# include	<SFML/Audio.hpp>
# include	<unordered_map>
# include	"Exceptions.hpp"
# include	"Map.hpp"

# define	WindowX (1400)
# define	WindowY (1000)
# define	PLAYERSCALE (1.3)
# define	FOODSCALE (1)
# define	TILESCALE (1)
# define	STONESCALE (1)

namespace		zappy
{
  class			UiManager
  {
  public:
    enum TextureID
      {
	CHARACTER_1_UP_1,
	CHARACTER_1_UP_2,
	CHARACTER_1_UP_3,
	CHARACTER_1_DOWN_1,
	CHARACTER_1_DOWN_2,
	CHARACTER_1_DOWN_3,
	CHARACTER_1_RIGHT_1,
	CHARACTER_1_RIGHT_2,
	CHARACTER_1_RIGHT_3,
	CHARACTER_1_LEFT_1,
	CHARACTER_1_LEFT_2,
	CHARACTER_1_LEFT_3,
	CHARACTER_1_CAST_1,
	CHARACTER_1_CAST_2,
	CHARACTER_1_CAST_3,
	CHARACTER_2_UP_1,
	CHARACTER_2_UP_2,
	CHARACTER_2_UP_3,
	CHARACTER_2_DOWN_1,
	CHARACTER_2_DOWN_2,
	CHARACTER_2_DOWN_3,
	CHARACTER_2_RIGHT_1,
	CHARACTER_2_RIGHT_2,
	CHARACTER_2_RIGHT_3,
	CHARACTER_2_LEFT_1,
	CHARACTER_2_LEFT_2,
	CHARACTER_2_LEFT_3,
	CHARACTER_2_CAST_1,
	CHARACTER_2_CAST_2,
	CHARACTER_2_CAST_3,
	CHARACTER_3_UP_1,
	CHARACTER_3_UP_2,
	CHARACTER_3_UP_3,
	CHARACTER_3_DOWN_1,
	CHARACTER_3_DOWN_2,
	CHARACTER_3_DOWN_3,
	CHARACTER_3_RIGHT_1,
	CHARACTER_3_RIGHT_2,
	CHARACTER_3_RIGHT_3,
	CHARACTER_3_LEFT_1,
	CHARACTER_3_LEFT_2,
	CHARACTER_3_LEFT_3,
	CHARACTER_3_CAST_1,
	CHARACTER_3_CAST_2,
	CHARACTER_3_CAST_3,
	CHARACTER_4_UP_1,
	CHARACTER_4_UP_2,
	CHARACTER_4_UP_3,
	CHARACTER_4_DOWN_1,
	CHARACTER_4_DOWN_2,
	CHARACTER_4_DOWN_3,
	CHARACTER_4_RIGHT_1,
	CHARACTER_4_RIGHT_2,
	CHARACTER_4_RIGHT_3,
	CHARACTER_4_LEFT_1,
	CHARACTER_4_LEFT_2,
	CHARACTER_4_LEFT_3,
	CHARACTER_4_CAST_1,
	CHARACTER_4_CAST_2,
	CHARACTER_4_CAST_3,
	CHARACTER_5_UP_1,
	CHARACTER_5_UP_2,
	CHARACTER_5_UP_3,
	CHARACTER_5_DOWN_1,
	CHARACTER_5_DOWN_2,
	CHARACTER_5_DOWN_3,
	CHARACTER_5_RIGHT_1,
	CHARACTER_5_RIGHT_2,
	CHARACTER_5_RIGHT_3,
	CHARACTER_5_LEFT_1,
	CHARACTER_5_LEFT_2,
	CHARACTER_5_LEFT_3,
	CHARACTER_5_CAST_1,
	CHARACTER_5_CAST_2,
	CHARACTER_5_CAST_3,
	CHARACTER_6_UP_1,
	CHARACTER_6_UP_2,
	CHARACTER_6_UP_3,
	CHARACTER_6_DOWN_1,
	CHARACTER_6_DOWN_2,
	CHARACTER_6_DOWN_3,
	CHARACTER_6_RIGHT_1,
	CHARACTER_6_RIGHT_2,
	CHARACTER_6_RIGHT_3,
	CHARACTER_6_LEFT_1,
	CHARACTER_6_LEFT_2,
	CHARACTER_6_LEFT_3,
	CHARACTER_6_CAST_1,
	CHARACTER_6_CAST_2,
	CHARACTER_6_CAST_3,
	CHARACTER_7_UP_1,
	CHARACTER_7_UP_2,
	CHARACTER_7_UP_3,
	CHARACTER_7_DOWN_1,
	CHARACTER_7_DOWN_2,
	CHARACTER_7_DOWN_3,
	CHARACTER_7_RIGHT_1,
	CHARACTER_7_RIGHT_2,
	CHARACTER_7_RIGHT_3,
	CHARACTER_7_LEFT_1,
	CHARACTER_7_LEFT_2,
	CHARACTER_7_LEFT_3,
	CHARACTER_7_CAST_1,
	CHARACTER_7_CAST_2,
	CHARACTER_7_CAST_3,
	CHARACTER_8_UP_1,
	CHARACTER_8_UP_2,
	CHARACTER_8_UP_3,
	CHARACTER_8_DOWN_1,
	CHARACTER_8_DOWN_2,
	CHARACTER_8_DOWN_3,
	CHARACTER_8_RIGHT_1,
	CHARACTER_8_RIGHT_2,
	CHARACTER_8_RIGHT_3,
	CHARACTER_8_LEFT_1,
	CHARACTER_8_LEFT_2,
	CHARACTER_8_LEFT_3,
	CHARACTER_8_CAST_1,
	CHARACTER_8_CAST_2,
	CHARACTER_8_CAST_3,
	CHARACTER_DIE_1,
	CHARACTER_DIE_2,
	CHARACTER_DIE_3,
	GRASS_1,
	GRASS_2,
	FOOD,
	LINEMATE,
	DERAUMERE,
	MENDIANE,
	PHIRAS,
	SIBUR,
	THYSTAME
      };

  protected:
    sf::RenderWindow _window;
    sf::Event	_event;
    sf::Font	_font;
    sf::View viewmap;
    sf::View viewmenu;
    std::unordered_map<int, sf::Texture *>	_tabTexture;
    sf::Vector2i cursor;
    float zoom;
    Map map;
    bool all;
    sf::Music _music;

  public:
    UiManager() {}
    ~UiManager() {}

    void	init();
    void	stop();
    void	clear();
    void	display();
    void	loadTexture(TextureID id,std::string const &file);
    void	drawSprite(float x, float y, TextureID id, float scale);
    void	drawMenuItem();
    void drawMenuPlayer();
    void SoundManager();
    int	pollEvents();
    void	setSpriteSheet(std::string const &path);
    void drawMap();
    Map &getMap();
    void drawPlayers();
  };
};

#endif                //UiManager_HPP
