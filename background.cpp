#include "background.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

Background::Background() 
{
	this->texture = new sf::Texture();
	this->tileset = new sf::Image();
}

void Background::LoadMap(std::string filename)
{
	std::string temp;
	std::ifstream openfile(filename.c_str());
	std::getline(openfile, this->tilesetname);
	std::getline(openfile, temp);
	this->tileWidth = atoi(temp.c_str());
	std::getline(openfile, temp);
	this->tileHeight = atoi(temp.c_str());

	std::getline(openfile, temp);
	this->width = atoi(temp.c_str());
	std::getline(openfile, temp);
	this->height = atoi(temp.c_str());

	this->data = new int[this->width * this->height];
	for (int y = 0; y < this->height; y += 1)
	{
		for (int x = 0; x < this->width; x += 1)
		{
			char temp;
			openfile >> this->data[x + y * this->width] >> temp;
		}
	}
	openfile.close();

	this->texture->create(this->width * this->tileWidth, this->height * this->tileHeight);
	this->tileset->loadFromFile("images/grid.png");

	sf::Image tile1, tile2, tile3, tile4;

	tile1.create(32, 32);
	tile2.create(32, 32);
	tile3.create(32, 32);
	tile4.create(32, 32);

	tile1.copy(*this->tileset, 0, 0, sf::IntRect(0, 0, this->tileWidth, this->tileHeight), true);
	tile2.copy(*this->tileset, 0, 0, sf::IntRect(this->tileWidth, 0, this->tileWidth, this->tileHeight), true);
	tile3.copy(*this->tileset, 0, 0, sf::IntRect(0, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile4.copy(*this->tileset, 0, 0, sf::IntRect(this->tileWidth, this->tileHeight, this->tileWidth, this->tileHeight), true);

	for (int y = 0; y < this->height; y += 1)
	{
		for (int x = 0; x < this->width; x += 1)
		{
			switch (this->data[x + y * this->width])
			{
				case 0:
					break;
				case 1:
					this->texture->update(tile1, x * 32, y * 32);
					break;
				case 2:
					this->texture->update(tile2, x * 32, y * 32);
					break;
				case 3:
					this->texture->update(tile3, x * 32, y * 32);
					break;
				case 4:
					this->texture->update(tile4, x * 32, y * 32);
					break;
			}
		}
	}

	this->setTexture(*this->texture);
}

/*int Background::Collision(Car* playercar, Direction direction)
{
	int x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width / 2) / this->tileWidth;
	int y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height / 2) / this->tileHeight;
	switch (direction)
	{
	case LEFT:
		x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width) / this->tileWidth;
		y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height / 2) / this->tileHeight;
		break;
	case RIGHT:
		x = (int)(playercar->getPosition().x) / this->tileWidth;
		y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height / 2) / this->tileHeight;
		break;
	case UP:
		x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width / 2) / this->tileWidth;
		y = (int)(playercar->getPosition().y) / this->tileHeight;
		break;
	case DOWN:
		x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width / 2) / this->tileWidth;
		y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height) / this->tileHeight;
		break;
	case TOP_LEFT:
		x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width) / this->tileWidth;
		y = (int)(playercar->getPosition().y) / this->tileHeight;
		break;
	case TOP_RIGHT:
		x = (int)(playercar->getPosition().x) / this->tileWidth;
		y = (int)(playercar->getPosition().y) / this->tileHeight;
		break;
	case BOTTOM_LEFT:
		x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width) / this->tileWidth;
		y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height) / this->tileHeight;
		break;
	case BOTTOM_RIGHT:
		x = (int)(playercar->getPosition().x) / this->tileWidth;
		y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height) / this->tileHeight;
		break;
	}
	return this->data[x + y * this->width];
}*/

