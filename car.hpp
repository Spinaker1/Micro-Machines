#ifndef car_hpp
#define car_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Car : public sf::Sprite
{
public:
    virtual void drive()=0;
};

#endif