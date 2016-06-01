#ifndef filemanager_hpp
#define filemanager_hpp
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

class File_Manager
{
private:
    friend class Game;
    friend class Engine;
    friend class Enemy;
    friend class Player;
    friend class Background;

    sf::Texture enemy_text;
    sf::Texture player_text;
    sf::Font font1;
    sf::Font font2;
    sf::Image background_tileset;
    std::ifstream background_map;
    sf::SoundBuffer music_buffer;
    sf::SoundBuffer enginesound_buffer;
    sf::Texture game_title;

public:
    File_Manager();
    ~File_Manager();
};

#endif