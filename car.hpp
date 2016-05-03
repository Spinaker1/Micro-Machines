#ifndef car_hpp
#define car_hpp
#include "globals.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Car : public sf::Sprite
{
protected:
    sf::Texture texture;

public:
    virtual void drive(int permission)=0;
    void set_vertices();
    sf::Vector2f vertices[4];
};

#endif