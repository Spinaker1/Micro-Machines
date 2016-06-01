#include "background.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>

Background::Background(File_Manager * fm)
{
	this->texture = new sf::Texture();
	file_manager=fm;
}

Background::~Background()
{
	delete texture;
	delete data;
}

void Background::LoadMap()
{
	std::string temp;
	std::getline(this->file_manager->background_map, this->tilesetname);
	std::getline(this->file_manager->background_map, temp);
	this->tileWidth = atoi(temp.c_str());
	std::getline(this->file_manager->background_map, temp);
	this->tileHeight = atoi(temp.c_str());

	std::getline(this->file_manager->background_map, temp);
	this->width = atoi(temp.c_str());
	std::getline(this->file_manager->background_map, temp);
	this->height = atoi(temp.c_str());

	this->data = new int[this->width * this->height];
	for (int y = 0; y < this->height; y += 1)
	{
		for (int x = 0; x < this->width; x += 1)
		{
			char temp;
			this->file_manager->background_map >> this->data[x + y * this->width] >> temp;
		}
	}

	this->texture->create(this->width * this->tileWidth, this->height * this->tileHeight);

	sf::Image tile1, tile2, tile3, tile4;

	tile1.create(32, 32);
	tile2.create(32, 32);
	tile3.create(32, 32);
	tile4.create(32, 32);

	tile1.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, 0, this->tileWidth, this->tileHeight), true);
	tile2.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, 0, this->tileWidth, this->tileHeight), true);
	tile3.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile4.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, this->tileHeight, this->tileWidth, this->tileHeight), true);

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

int Background::background_collision(Player* playercar, Direction direction)
{
	int x = (int)(playercar->getPosition().x + playercar->getGlobalBounds().width / 2) / this->tileWidth;
	int y = (int)(playercar->getPosition().y + playercar->getGlobalBounds().height / 2) / this->tileHeight;
	switch (direction)
	{
	case up:
		x = (int)(playercar->vertices[UP].x) / this->tileWidth;
		y = (int)(playercar->vertices[UP].y) / this->tileHeight;
		break;
	case down:
		x = (int)(playercar->vertices[DOWN].x) / this->tileWidth;
		y = (int)(playercar->vertices[DOWN].y) / this->tileHeight;
		break;
	}
	return this->data[x + y * this->width];
}

