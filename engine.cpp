#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"
#include <iostream>

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
    sf::Vector2f last_player_position=player->getPosition();
    if (cars_collision()) player->drive(PERMISSION_RIDE_BACK);
    else player->drive(PERMISSION_RIDE);
    view->setCenter(player->getPosition());
    window->setView(*view);
    window->clear(sf::Color::Black);
    window->draw(*background);
    window->draw(*enemy);
    window->draw(*player);



    window->display();
}

bool Engine::cars_collision()
{
    if (enemy->getRotation() == 0 || enemy->getRotation()==90 || enemy->getRotation()==180 || enemy->getRotation()==270)
    {
        double A = enemy->vertices[0].x;
        double B = enemy->vertices[2].x;
        double C = enemy->vertices[0].y;
        double D = enemy->vertices[2].y;
        for (int i = 0; i <= 7; i++)
        {
            double x = player->vertices[i].x;
            double y = player->vertices[i].y;
            if (enemy->getRotation() == 0 && x < A && x > B && y < C && y > D) return true;
            if (enemy->getRotation() == 90 && x > A && x < B && y < C && y > D) return true;
            if (enemy->getRotation() == 180 && x > A && x < B && y > C && y < D) return true;
            if (enemy->getRotation() == 270 && x < A && x > B && y > C && y < D) return true;
        }
    }
    else
    {
        double a[4],b[4];
        for (int i = 0; i <= 3; i++)
        {
            int n;
            if (i==0) n=3;
            else n=i-1;
            double x1=enemy->vertices[i].x;
            double x2=enemy->vertices[n].x;
            double y1=enemy->vertices[i].y;
            double y2=enemy->vertices[n].y;
            a[i]=(y1-y2)/(x1-x2);
            b[i]=y1-a[i]*x1;
        }
        for (int i = 0; i <= 5; i++)
        {
            double x = player->vertices[i].x;
            double y = player->vertices[i].y;

            if (y<a[0]*x+b[0] && y<a[1]*x+b[1] && y>a[2]*x+b[2] && y>a[3]*x+b[3]) return true;
            if (y>a[0]*x+b[0] && y>a[1]*x+b[1] && y<a[2]*x+b[2] && y<a[3]*x+b[3]) return true;
            if (y<a[0]*x+b[0] && y>a[1]*x+b[1] && y>a[2]*x+b[2] && y<a[3]*x+b[3]) return true;
            if (y>a[0]*x+b[0] && y<a[1]*x+b[1] && y<a[2]*x+b[2] && y>a[3]*x+b[3]) return true;
        }
    }
    return false;
}
