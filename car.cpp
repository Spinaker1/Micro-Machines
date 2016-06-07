#include "car.hpp"
#include <math.h>


//Wyznacza punkty na obwodzie samochodu (wierzcholki i srodki bokow).
void Car::set_vertices()
{
    vertices[UPPER_RIGHT].x=this->getPosition().x+CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[UPPER_RIGHT].y=this->getPosition().y+CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[UPPER_LEFT].x=this->getPosition().x+CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[UPPER_LEFT].y=this->getPosition().y+CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[DOWN_LEFT].x=this->getPosition().x-CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[DOWN_LEFT].y=this->getPosition().y-CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[DOWN_RIGHT].x=this->getPosition().x-CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[DOWN_RIGHT].y=this->getPosition().y-CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[UP].x=this->getPosition().x+CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2;
    vertices[UP].y=this->getPosition().y+CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2;
    vertices[DOWN].x=this->getPosition().x-CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2;
    vertices[DOWN].y=this->getPosition().y-CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2;
}
