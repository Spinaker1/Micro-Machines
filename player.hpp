#ifndef player_hpp
#define player_hpp
#include "car.hpp"


class Player : public  Car
{
private:
    sf::Texture texture;
public:
    Player(sf::Vector2f vector);
    Player(double x, double y);
    void drive();
};

#endif