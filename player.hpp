#ifndef player_hpp
#define player_hpp
#include "car.hpp"


class Player : public  Car
{
public:
    Player(sf::Vector2f vector, double rotation);
    Player(double x, double y, double rotation);
    void drive(int permission);
};

#endif