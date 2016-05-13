#include "enemy.hpp"
#include "globals.hpp"



Enemy::Enemy(sf::Vector2f vector, double rotation)
{
    this->texture.loadFromFile("images/enemy.png");
    this->setTexture(texture);
    this->setPosition(vector);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
}

Enemy::Enemy(double x, double y, double rotation)
{
    this->texture.loadFromFile("images/enemy.png");
    this->setTexture(texture);
    this->setPosition(x,y);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
}

void Enemy::drive(int permission)
{
;
}

