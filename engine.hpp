#ifndef engine_hpp
#define engine_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "background.hpp"
#include "globals.hpp"
#include "filemanager.hpp"

class Engine
{
private:
    friend class Game;

    sf::RenderWindow * window;
    sf::View * view;
    Background * background;
    Player * player;
    Enemy * enemy;
    sf::Clock * start_clock;
    sf::Clock * clock;
    File_Manager * file_manager;

    void timer();
    int cars_collision(Car *car1, Car *car2);
    bool finish(Car * car);
public:
    Engine(sf::RenderWindow * win, File_Manager * fm);
    ~Engine();
    bool update();
};

#endif
