#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"

Engine::Engine(sf::RenderWindow * win)
{
window=win;
background=new Background;
view=new sf::View(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), sf::Vector2f(WINDOW_LENGTH, WINDOW_HEIGHT));
player=new Player(PLAYER_START_X,PLAYER_START_Y,PLAYER_START_ROTATION);
enemy=new Enemy(ENEMY_START_X,ENEMY_START_Y,ENEMY_START_ROTATION);
}

Engine::~Engine()
{
    delete view;
    delete background;
    delete player;
    delete enemy;
}

void Engine::update()
{
    player->drive(PERMISSION_RIDE);
    view->setCenter(player->getPosition());
    window->setView(*view);
    window->clear(sf::Color::Black);
    window->draw(*background);
    window->draw(*enemy);
    window->draw(*player);
    window->display();
}

