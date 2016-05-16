#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"
#include "background.hpp"
#include <iostream>
#include <math.h>

Engine::Engine(sf::RenderWindow * win)
{
window=win;
background=new Background;
background->LoadMap("images/test.map");
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
        player->drive(cars_collision(player, enemy));
        enemy->drive(cars_collision(enemy, player));
        view->setCenter(player->getPosition());
        window->setView(*view);
        window->clear(sf::Color::Black);
        window->draw(*background);
        window->draw(*enemy);
        window->draw(*player);
        window->display();
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window->close();
            }

        }
}

int Engine::cars_collision(Car *car1, Car *car2)
{
    if (car2->getRotation() == 0 || car2->getRotation()==90 || car2->getRotation()==180 || car2->getRotation()==270)
    {
        double A = car2->vertices[0].x;
        double B = car2->vertices[2].x;
        double C = car2->vertices[0].y;
        double D = car2->vertices[2].y;
        for (int i = 0; i <= 5; i++)
        {
            double x = car1->vertices[i].x;
            double y = car1->vertices[i].y;
            if (car2->getRotation() == 0 && x < A && x > B && y < C && y > D) return i;
            if (car2->getRotation() == 90 && x > A && x < B && y < C && y > D) return i;
            if (car2->getRotation() == 180 && x > A && x < B && y > C && y < D) return i;
            if (car2->getRotation() == 270 && x < A && x > B && y > C && y < D) return i;
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
            double x1=car2->vertices[i].x;
            double x2=car2->vertices[n].x;
            double y1=car2->vertices[i].y;
            double y2=car2->vertices[n].y;
            a[i]=(y1-y2)/(x1-x2);
            b[i]=y1-a[i]*x1;
        }
        for (int i = 0; i <= 5; i++)
        {
            double x = car1->vertices[i].x;
            double y = car1->vertices[i].y;

            if (y<a[0]*x+b[0] && y<a[1]*x+b[1] && y>a[2]*x+b[2] && y>a[3]*x+b[3]) return i;
            if (y>a[0]*x+b[0] && y>a[1]*x+b[1] && y<a[2]*x+b[2] && y<a[3]*x+b[3]) return i;
            if (y<a[0]*x+b[0] && y>a[1]*x+b[1] && y>a[2]*x+b[2] && y<a[3]*x+b[3]) return i;
            if (y>a[0]*x+b[0] && y<a[1]*x+b[1] && y<a[2]*x+b[2] && y>a[3]*x+b[3]) return i;
        }
    }
    return -1;
}