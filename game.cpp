#include "game.hpp"
#include "globals.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"
#include "filemanager.hpp"
#include <iostream>


Game::Game() {
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT, 32), "Golden Mercedes Racing");
    window->setFramerateLimit(FRAMERATE_LIMIT);
    sf::Vector2i vector(100,100);
    window->setPosition(vector);
    file_manager = new File_Manager;
    engine = new Engine(window,file_manager);
    state = MENU;
    music.setBuffer(file_manager->music_buffer);
    music.setLoop(true);
    title=new sf::Sprite;
    title->setTexture(file_manager->game_title);
    title->setPosition(0,10);
    enginesound.setBuffer(file_manager->enginesound_buffer);
    enginesound.setLoop(true);
}

Game::~Game() {
    delete window;
    delete engine;
    delete file_manager;
}

void Game::runGame() {
    while (window->isOpen()) {
        switch (state) {
            case GAME_OVER:
                game_over();
                break;
            case MENU:
                menu();
                break;
            case GAME:
                if (engine->update())
                {
                    finish_window = new sf::RenderWindow(sf::VideoMode(400, 300, 32), "");
                    state = GAME_OVER;
                }

                break;
            case END:
                window->close();
        };
    }
}

void Game::menu()
{
    music.play();
    const int ile = 2;
    sf::Text tekst[ile];
    std::string str[] = {"Play","Exit"};
    for(int i=0;i<ile;i++)
    {
        tekst[i].setFont(file_manager->font1);
        tekst[i].setCharacterSize(50);
        tekst[i].setString(str[i]);
        tekst[i].setPosition(WINDOW_LENGTH/2-tekst[i].getGlobalBounds().width/2,150+i*120);
    }
    while(state == MENU) {
        sf::Vector2f mouse;
        mouse.x=sf::Mouse::getPosition().x-window->getPosition().x;
        mouse.y=sf::Mouse::getPosition().y-window->getPosition().y;
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                state = END;
            }
            else if (tekst[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased &&
                     event.mouseButton.button == sf::Mouse::Left) {
                state = END;

            }
            else if (tekst[0].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased &&
                     event.mouseButton.button == sf::Mouse::Left) {
                music.stop();
                enginesound.play();
                engine->clock->restart();
                engine->start_clock->restart();
                state = GAME;
            }
        }
        for (int i = 0; i < ile; i++)
        {
            if (tekst[i].getGlobalBounds().contains(mouse)) tekst[i].setColor(sf::Color::Yellow);
            else tekst[i].setColor(sf::Color::White);
        }
        window->clear(sf::Color::Black);
        window->draw(*title);
        for (int i = 0; i < ile; i++)
        {
            window->draw(tekst[i]);
        }
        window->display();
    }
}


void Game::game_over()
{
    enginesound.stop();
    sf::Vector2i vector(300,200);
    finish_window->setPosition(vector);
    sf::Text title("MENU",file_manager->font1,50);
    title.setStyle(sf::Text::Bold);
    title.setPosition(200-title.getGlobalBounds().width/2,200);
    sf::Vector2f mouse;
    sf::Text text("",file_manager->font1,50);
    text.setStyle(sf::Text::Bold);
    text.setPosition(100-text.getGlobalBounds().width/2,20);
    if (engine->finish(engine->enemy))
    {
        text.setString("CPU WINS!");
    }
    if (engine->finish(engine->player))
    {
        text.setString("YOU WIN!");
    }
    mouse.x=sf::Mouse::getPosition().x-finish_window->getPosition().x;
    mouse.y=sf::Mouse::getPosition().y-finish_window->getPosition().y;
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
    while (finish_window->pollEvent(event))
    {
        if (title.getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased &&
            event.mouseButton.button == sf::Mouse::Left) {
            state = MENU;
            finish_window->close();
            sf::View view(sf::Vector2f(400, 300), sf::Vector2f(WINDOW_LENGTH, WINDOW_HEIGHT));
            window->setView(view);
            delete engine->player;
            delete engine->enemy;
            delete engine->start_clock;
            engine->player = new Player(PLAYER_START_X, PLAYER_START_Y, PLAYER_START_ROTATION, engine->background, file_manager);
            engine->enemy = new Enemy(ENEMY_START_X, ENEMY_START_Y, ENEMY_START_ROTATION, file_manager);
            engine->start_clock = new sf::Clock;
        }
    }
    if (title.getGlobalBounds().contains(mouse)) {
        title.setColor(sf::Color::Yellow);
    }
    finish_window->clear(sf::Color::Black);
    finish_window->draw(title);
    finish_window->draw(text);
    finish_window->display();
}