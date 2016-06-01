#ifndef car_hpp
#define car_hpp
#include "globals.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "filemanager.hpp"


class Car : public sf::Sprite
{
protected:
    sf::Texture texture;
    double speed;
	File_Manager * file_manager;

public:
    virtual void drive(int permission)=0;
    void set_vertices();
    sf::Vector2f vertices[8];
};

#endif
