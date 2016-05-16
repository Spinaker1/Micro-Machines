#ifndef game_hpp
#define game_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"

class Game
{
private:
    sf::RenderWindow * window;
    sf::Font * font;
    Engine * engine;
    void menu();
    enum GameState {MENU,GAME,GAME_OVER,END};
    GameState state;

public:
    Game();
    ~Game();
    void runGame();
};

#endif