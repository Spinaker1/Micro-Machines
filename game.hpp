#ifndef game_hpp
#define game_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"
#include "filemanager.hpp"


class Game
{
private:
    sf::RenderWindow * window;
    sf::RenderWindow * finish_window;
    Engine * engine;
    File_Manager * file_manager;
    void menu();
    enum GameState {MENU,GAME,GAME_OVER,END};
    GameState state;
    sf::Sound music;
    sf::Sprite * title;
    sf::Sound enginesound;

public:
    Game();
    ~Game();
    void runGame();
    void game_over();
};

#endif