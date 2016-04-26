#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "player.hpp"
#include "background.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT, 32), "Micro-Machines");
    window.setFramerateLimit(FRAMERATE_LIMIT);
    Player car(PLAYER_START_X,PLAYER_START_Y);
    Background background;
    sf::View view(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y), sf::Vector2f(WINDOW_LENGTH, WINDOW_HEIGHT));
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed )
            {
                window.close();
            }
        };
        car.drive();
        window.clear(sf::Color::Black);
        window.draw(background);
        window.draw(car);
        view.setCenter(car.getPosition());
        window.setView(view);
        window.display();
    }
    return 0;
}

