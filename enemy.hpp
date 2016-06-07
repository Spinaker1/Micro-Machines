#ifndef enemy_hpp
#define enemy_hpp
#include "car.hpp"
#include "filemanager.hpp"
#include <vector>


class Enemy : public  Car
{
private:
    int track_counter;
    std::vector<sf::Vector2f> track;

public:
    Enemy(double x, double y, double rotation, File_Manager * fm);
    void drive(int permission);
    bool take_point(sf::Vector2f point);
};

#endif