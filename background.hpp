#ifndef background_hpp
#define background_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "car.hpp"

typedef enum
{
	NONE = -1,
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3,
	TOP_LEFT = 4,
	TOP_RIGHT = 5,
	BOTTOM_LEFT = 6,
	BOTTOM_RIGHT = 7
} Direction;

class Background : public sf::Sprite
{
private:
	sf::Texture* texture;
	sf::Image* tileset;
public:
	Background();
	void LoadMap(std::string filename);
	void DrawMap(sf::RenderWindow* window);
	int Collision(Car* car);
protected:
	std::string tilesetname;
	int width, height, tileWidth, tileHeight;
	int* data;
	
};

#endif
