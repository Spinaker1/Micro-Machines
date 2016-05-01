#ifndef engine_hpp
#define engine_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "background.hpp"
#include "globals.hpp"

class Engine
{
private:
    sf::RenderWindow * window;
    sf::View * view;
    Background * background;
    Player * player;
    Enemy * enemy;

public:
    Engine(sf::RenderWindow * win);
    ~Engine();
    void update();
    bool check_collision(sf::Vector2f *A,int sizeA, sf::Vector2f *B, int sizeB, sf::Vector2f &offset);
};

#endif