#include "background.hpp"

Background::Background()
{
    this->texture.loadFromFile("background.jpg");
    this->setTexture(texture);
}