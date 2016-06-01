#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"
#include "background.hpp"
#include "globals.hpp"
#include <iostream>
#include <cstdlib>
#include <math.h>

Engine::Engine(sf::RenderWindow *win, File_Manager *fm) {
    file_manager = fm;
    window = win;
    background = new Background(file_manager);
    background->LoadMap();
    view = new sf::View(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), sf::Vector2f(WINDOW_LENGTH, WINDOW_HEIGHT));
    player = new Player(PLAYER_START_X, PLAYER_START_Y, PLAYER_START_ROTATION, background, file_manager);
    enemy = new Enemy(ENEMY_START_X, ENEMY_START_Y, ENEMY_START_ROTATION, file_manager);
    clock = new sf::Clock;
    start_clock = new sf::Clock;
    view->zoom(1.2);
}

Engine::~Engine() {
    delete view;
    delete background;
    delete player;
    delete enemy;
    delete start_clock;
    delete clock;
    delete view;
}

bool Engine::update() {
    sf::Text text("", file_manager->font2, 140);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::Red);
    if (!(finish(enemy)) && !(finish(player))) {
        int time = start_clock->getElapsedTime().asSeconds();
        if (time <= 2)
        {
            text.setString("3");
        }
        if (time > 2 && time <= 3)
            text.setString("2");
        if (time > 3 && time <= 4)text.setString("1");
        if (time > 4) {
            enemy->drive(cars_collision(enemy, player));
            player->drive(cars_collision(player, enemy));
        }
        if (time > 4 && time <= 5)
            text.setString("Start!");
    }
    else {
        return true;
    }
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(view->getCenter().x, view->getCenter().y - 200);
    view->setCenter(player->getPosition());
    window->setView(*view);
    window->clear(sf::Color::Black);
    window->draw(*background);
    window->draw(*enemy);
    window->draw(*player);
    window->draw(text);
    this->timer();
    window->display();;
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window->close();
    }
    std::cout << view->getCenter().x << std::endl;
    return false;
}

int Engine::cars_collision(Car *car1, Car *car2) {
    if (car2->getRotation() == 0 || car2->getRotation() == 90 || car2->getRotation() == 180 ||
        car2->getRotation() == 270) {
        double A = car2->vertices[UPPER_RIGHT].x;
        double B = car2->vertices[DOWN_LEFT].x;
        double C = car2->vertices[UPPER_RIGHT].y;
        double D = car2->vertices[DOWN_LEFT].y;
        for (int i = 0; i <= 5; i++) {
            double x = car1->vertices[i].x;
            double y = car1->vertices[i].y;
            if (car2->getRotation() == 0 && x < A && x > B && y < C && y > D) return i;
            if (car2->getRotation() == 90 && x > A && x < B && y < C && y > D) return i;
            if (car2->getRotation() == 180 && x > A && x < B && y > C && y < D) return i;
            if (car2->getRotation() == 270 && x < A && x > B && y > C && y < D) return i;
        }
    }
    else {
        double a[4], b[4];
        for (int i = 0; i <= 3; i++) {
            int n;
            if (i == 0) n = 3;
            else n = i - 1;
            double x1 = car2->vertices[i].x;
            double x2 = car2->vertices[n].x;
            double y1 = car2->vertices[i].y;
            double y2 = car2->vertices[n].y;
            a[i] = (y1 - y2) / (x1 - x2);
            b[i] = y1 - a[i] * x1;
        }
        for (int i = 0; i <= 5; i++) {
            double x = car1->vertices[i].x;
            double y = car1->vertices[i].y;

            if (y < a[0] * x + b[0] && y < a[1] * x + b[1] && y > a[2] * x + b[2] && y > a[3] * x + b[3]) return i;
            if (y > a[0] * x + b[0] && y > a[1] * x + b[1] && y < a[2] * x + b[2] && y < a[3] * x + b[3]) return i;
            if (y < a[0] * x + b[0] && y > a[1] * x + b[1] && y > a[2] * x + b[2] && y < a[3] * x + b[3]) return i;
            if (y > a[0] * x + b[0] && y < a[1] * x + b[1] && y < a[2] * x + b[2] && y > a[3] * x + b[3]) return i;
        }
    }
    return -1;
}

void Engine::timer() {
    if (start_clock->getElapsedTime().asSeconds() > 5) {
        std::string tmp;
        int seconds = clock->getElapsedTime().asSeconds();
        int minutes = floor(seconds / 60);
        seconds = seconds % 60;
        if (seconds < 10)
            sprintf((char *) tmp.c_str(), "%d:0%d", minutes, seconds);
        else
            sprintf((char *) tmp.c_str(), "%d:%d", minutes, seconds);
        std::string str = tmp.c_str();
        sf::Text time(str, file_manager->font2, 50);
        time.setStyle(sf::Text::Bold);
        time.setPosition(player->getPosition().x - 450, player->getPosition().y - 350);
        window->draw(time);
    }
    else
        clock->restart();
}

bool Engine::finish(Car *car) {
    for (int i = 0; i <= 5; i++) {
        if (car->vertices[i].y > 7500) {
            return true;
        }
    }
    return false;
}