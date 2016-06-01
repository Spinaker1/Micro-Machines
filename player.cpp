#include "player.hpp"
#include "globals.hpp"
#include "background.hpp"
#include <math.h>



Player::Player(double x, double y, double rotation, Background* background, File_Manager * fm)
{
	this->file_manager=fm;
    this->speed=0;
    this->setTexture(this->file_manager->player_text);
    this->setPosition(x,y);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
    this->background=background;

}

void Player::drive(int permission)
{
	float max_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		max_speed=MAX_SPEED_FORWARD;
		this->speed+=0.1;
		if (permission==0 || permission==1 || permission==4)
		{
			speed=0;
		}
		if (this->background->background_collision(this, up) == 3)
		{
			speed=0;
		}
		if (this->background->background_collision(this, up) == 2)
		{
			max_speed=MAX_SPEED_FORWARD/2;
		}
		if (this->speed>=max_speed) this->speed=max_speed;
	}
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && speed>0.01) 
    {
		this->speed-=0.1;
		if (permission==0 || permission==1 || permission==4)
		{
			speed=0;
		}
		if (this->background->background_collision(this, up) == 3)
		{
			speed=0;
		}
	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
		this->speed-=0.1;
		max_speed=MAX_SPEED_BACK;
		if (speed < 0 && (permission==2 || permission==3 || permission==5))
		{
			speed=0;
		}
		if (this->background->background_collision(this, down) == 3)
		{
			speed=0;
		}
		if (this->background->background_collision(this, down) == 2)
		{
			max_speed=MAX_SPEED_BACK/2;
		}
		if (this->speed<=-max_speed) this->speed=-max_speed;
	}
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && speed<-0.01) 
    {
		this->speed+=0.1;
		if (this->speed<=-MAX_SPEED_BACK) this->speed=-MAX_SPEED_BACK;
		if (speed < 0 && (permission==2 || permission==3 || permission==5))
		{
			speed=0;
		}
		if (this->background->background_collision(this, down) == 3)
		{
			speed=0;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed=0;
	this->move(speed*cos(this->getRotation()*M_PI/180),this->speed*sin(this->getRotation()*M_PI/180));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->rotate(-ROTATION_ANGLE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->rotate(ROTATION_ANGLE);
    }
    this->set_vertices();
}
