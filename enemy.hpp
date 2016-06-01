#ifndef enemy_hpp
#define enemy_hpp
#include "car.hpp"
#include "filemanager.hpp"


class Enemy : public  Car
{
private:
    int track_counter;

public:
    Enemy(double x, double y, double rotation, File_Manager * fm);
    void drive(int permission);
    bool take_point(sf::Vector2f point);
};

#endif