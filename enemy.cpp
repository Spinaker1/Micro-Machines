#include "enemy.hpp"
#include "globals.hpp"



Enemy::Enemy(sf::Vector2f vector, double rotation)
{
    this->texture.loadFromFile("images/enemy.png");
    this->setTexture(texture);
    this->setPosition(vector);
    this->setRotation(rotation);
    this->setOrigin(PLAYER_LENGTH/2,PLAYER_HEIGHT/2);
}

Enemy::Enemy(double x, double y, double rotation)
{
    this->texture.loadFromFile("images/enemy.png");
    this->setTexture(texture);
    this->setPosition(x,y);
    this->setRotation(rotation);
    this->setOrigin(PLAYER_LENGTH/2,PLAYER_HEIGHT/2);
}

void Enemy::drive(int permission)
{
    ;
}

