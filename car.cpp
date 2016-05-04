#include "car.hpp"

void Car::set_vertices()
{
    vertices[0].x=this->getPosition().x+CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[0].y=this->getPosition().y+CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[1].x=this->getPosition().x+CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[1].y=this->getPosition().y+CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[2].x=this->getPosition().x-CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[2].y=this->getPosition().y-CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2-CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[3].x=this->getPosition().x-CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[3].y=this->getPosition().y-CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2+CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[4].x=this->getPosition().x+CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2;
    vertices[4].y=this->getPosition().y+CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2;
    vertices[5].x=this->getPosition().x-CAR_LENGTH*cos(this->getRotation()*M_PI/180)/2;
    vertices[5].y=this->getPosition().y-CAR_LENGTH*sin(this->getRotation()*M_PI/180)/2;
    vertices[6].x=this->getPosition().x+CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[6].y=this->getPosition().y+CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
    vertices[7].x=this->getPosition().x-CAR_HEIGHT*sin(-this->getRotation()*M_PI/180)/2;
    vertices[7].y=this->getPosition().y-CAR_HEIGHT*cos(-this->getRotation()*M_PI/180)/2;
}