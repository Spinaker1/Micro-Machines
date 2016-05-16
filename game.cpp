#include "game.hpp"
#include "globals.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "engine.hpp"

Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT, 32), "Micro-Machines");
    window->setFramerateLimit(FRAMERATE_LIMIT);
    engine=new Engine(window);
    font=new sf::Font;
    if(!font->loadFromFile("fonts/courier-new.ttf"))
    {
        return;
    }
    state=MENU;
}

Game::~Game()
{
    delete window;
    delete font;
}

void Game::runGame()
{
    while(window->isOpen())
    {
        switch (state)
        {
            case GameState::MENU:
                menu();
                break;
            case GameState::GAME:
                engine->update();
                break;
            case GameState::END:
                window->close();
        };
    }
}

void Game::menu()
{
    sf::Text title("Gold Mercedes Racing",*font,60);
    title.setStyle(sf::Text::Bold);
    title.setPosition(WINDOW_LENGTH/2-title.getGlobalBounds().width/2,20);
    const int ile = 2;
    sf::Text tekst[ile];
    std::string str[] = {"Play","Exit"};
    for(int i=0;i<ile;i++)
    {
        tekst[i].setFont(*font);
        tekst[i].setCharacterSize(65);
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
                state = GAME;
            }
        }
        for (int i = 0; i < ile; i++)
        {
            if (tekst[i].getGlobalBounds().contains(mouse)) tekst[i].setColor(sf::Color::Yellow);
            else tekst[i].setColor(sf::Color::White);
        }

        window->clear(sf::Color::Black);

        window->draw(title);
        for (int i = 0; i < ile; i++)
        {
            window->draw(tekst[i]);
        }
        window->display();
    }
}

