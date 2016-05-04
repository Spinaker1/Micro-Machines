#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "engine.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT, 32), "Micro-Machines");
    window.setFramerateLimit(FRAMERATE_LIMIT);
    Engine engine(&window);
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
        engine.update();
    }
    return 0;
}

