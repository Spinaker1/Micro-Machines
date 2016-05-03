#include "player.hpp"
#include "globals.hpp"



Player::Player(sf::Vector2f vector, double rotation)
{
    this->texture.loadFromFile("images/player.png");
    this->setTexture(texture);
    this->setPosition(vector);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
}

Player::Player(double x, double y, double rotation)
{
    this->texture.loadFromFile("images/player.png");
    this->setTexture(texture);
    this->setPosition(x,y);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
}

void Player::drive(int permission)
{
    sf::Vector2f speed(0,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && permission!=PERMISSION_RIDE_BACK)
    {
        speed.x=cos(this->getRotation()*M_PI/180)*MAX_SPEED_FORWARD;
        speed.y=sin(this->getRotation()*M_PI/180)*MAX_SPEED_FORWARD;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && permission!=PERMISSION_RIDE_FORWARD)
    {
        speed.x=-cos(this->getRotation()*M_PI/180)*MAX_SPEED_BACK;
        speed.y=-sin(this->getRotation()*M_PI/180)*MAX_SPEED_BACK;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && permission==PERMISSION_RIDE)
    {
        this->rotate(-ROTATION_ANGLE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && permission==PERMISSION_RIDE)
    {
        this->rotate(ROTATION_ANGLE);
    }
    this->move(speed);
    this->set_vertices();
}

