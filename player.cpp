#include "player.hpp"
#include "globals.hpp"



Player::Player(sf::Vector2f vector)
{
    this->texture.loadFromFile("car.png");
    this->setTexture(texture);
    this->setPosition(vector);
    this->setRotation(0);
    this->setOrigin(PLAYER_LENGTH/2,PLAYER_HEIGHT/2);
}

Player::Player(double x, double y)
{
    this->texture.loadFromFile("car.png");
    this->setTexture(texture);
    this->setPosition(x,y);
    this->setRotation(0);
    this->setOrigin(PLAYER_LENGTH/2,PLAYER_HEIGHT/2);
}

void Player::drive()
{
    sf::Vector2f speed(0,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        speed.x=cos(this->getRotation()*M_PI/180)*MAX_SPEED_FORWARD;
        speed.y=sin(this->getRotation()*M_PI/180)*MAX_SPEED_FORWARD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        speed.x=-cos(this->getRotation()*M_PI/180)*MAX_SPEED_BACK;
        speed.y=-sin(this->getRotation()*M_PI/180)*MAX_SPEED_BACK;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->rotate(-ROTATION_ANGLE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->rotate(ROTATION_ANGLE);
    }
    this->move(speed);
}

