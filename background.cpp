#include "background.hpp"

Background::Background()
{
    this->texture.loadFromFile("images/background.jpg");
    this->setTexture(texture);
}