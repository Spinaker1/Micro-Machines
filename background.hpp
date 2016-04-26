#ifndef background_hpp
#define background_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Background : public sf::Sprite
{
private:
    sf::Texture texture;
public:
    Background();
};

#endif