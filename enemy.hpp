#ifndef enemy_hpp
#define enemy_hpp
#include "car.hpp"


class Enemy : public  Car
{
public:
    Enemy(sf::Vector2f vector, double rotation);
    Enemy(double x, double y, double rotation);
    void drive(int permission);
};

#endif