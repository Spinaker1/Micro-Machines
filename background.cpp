#include "background.hpp"

Background::Background()
{
    this->texture.loadFromFile("images/background.png");
    this->setTexture(texture);
}