#ifndef background_hpp
#define background_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.hpp"


class Background : public sf::Sprite
{
private:
	sf::Texture* texture;
	File_Manager * file_manager;
public:
	Background(File_Manager * fm);
	~Background();
	void LoadMap();
	void DrawMap(sf::RenderWindow* window);
	int background_collision(Player * playercar, Direction direction);
protected:
	std::string tilesetname;
	int width, height, tileWidth, tileHeight;
	int* data;
	
};

#endif
