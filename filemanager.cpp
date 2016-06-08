#include "filemanager.hpp"


File_Manager::File_Manager()
{
    if(!(this->enemy_text.loadFromFile("images/enemy.png")))
        exit(69);
    if(!(this->player_text.loadFromFile("images/player.png")))
        exit(69);
    if((!this->font1.loadFromFile("fonts/courier-new.ttf")))
        exit(69);
    if((!this->font2.loadFromFile("fonts/fenwick-outline.ttf")))
        exit(69);
    if(!(this->background_tileset.loadFromFile("images/tileset2.png")))
        exit(69);
    this->background_map.open("images/mapa.map");
    if (this->background_map.bad())
        exit(69);
    if(!(this->music_buffer.loadFromFile("sounds/menu_music.wav")))
        exit(69);
    if(!(this->enginesound_buffer.loadFromFile("sounds/enginesound.wav")))
        exit(69);
    if(!(this->game_title.loadFromFile("images/title.gif")))
        exit(69);
}

File_Manager::~File_Manager()
{
    background_map.close();
}
