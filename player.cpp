#include "player.hpp"
#include "globals.hpp"
#include <math.h>



Player::Player(sf::Vector2f vector, double rotation)
{
    this->speed=0;
    this->texture.loadFromFile("images/player.png");
    this->setTexture(texture);
    this->setPosition(vector);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
}

Player::Player(double x, double y, double rotation)
{
    this->speed=0;
    this->texture.loadFromFile("images/player.png");
    this->setTexture(texture);
    this->setPosition(x,y);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
}

void Player::drive(int permission)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->speed+=0.1;
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && speed>0.01) this->speed-=0.1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->speed-=0.1;
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && speed<-0.01) this->speed+=0.1;
    if (this->speed>=MAX_SPEED_FORWARD) this->speed=MAX_SPEED_FORWARD;
    if (this->speed<=-MAX_SPEED_BACK) this->speed=-MAX_SPEED_BACK;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->rotate(-ROTATION_ANGLE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->rotate(ROTATION_ANGLE);
    }
    if (speed > 0 && (permission==0 || permission==1 || permission==4))
    {
        speed=0;
    }
    if (speed < 0 && (permission==2 || permission==3 || permission==5))
    {
        speed=0;
    }
    this->move(speed*cos(this->getRotation()*M_PI/180),this->speed*sin(this->getRotation()*M_PI/180));
    this->set_vertices();
}

