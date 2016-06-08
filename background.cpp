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
	delete[] data;
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

	sf::Image tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tile9, tile10, tile11, tile12, tile13, tile14, tile15, tile16, tile17, tile18, tile19, tile20, tile21, tile22, tile23, tile24, tile25, tile26, tile27, tile28, tile29, tile30, tile31, tile32, tile33, tile34, tile35, tile36, tile37, tile38, tile39, tile40, tile41, tile42, tile43, tile44, tile45, tile46, tile47, tile48, tile49, tile50, tile51, tile52, tile53, tile54, tile55, tile56, tile57, tile58, tile59, tile60, tile61, tile62, tile63, tile64, tile65, tile66, tile67, tile68, tile69, tile70, tile71, tile72, tile73, tile74, tile75, tile76, tile77, tile78, tile79, tile80, tile81, tile82, tile83, tile84, tile85, tile86, tile87, tile88;

	tile1.create(32, 32);
	tile2.create(32, 32);
	tile3.create(32, 32);
	tile4.create(32, 32);
	tile5.create(32, 32);
	tile6.create(32, 32);
	tile7.create(32, 32);
	tile8.create(32, 32);
	tile9.create(32, 32);
	tile10.create(32, 32);
	tile11.create(32, 32);
	tile12.create(32, 32);
	tile13.create(32, 32);
	tile14.create(32, 32);
	tile15.create(32, 32);
	tile16.create(32, 32);
	tile17.create(32, 32);
	tile18.create(32, 32);
	tile19.create(32, 32);
	tile20.create(32, 32);
	tile21.create(32, 32);
	tile22.create(32, 32);
	tile23.create(32, 32);
	tile24.create(32, 32);
	tile25.create(32, 32);
	tile26.create(32, 32);
	tile27.create(32, 32);
	tile28.create(32, 32);
	tile29.create(32, 32);
	tile30.create(32, 32);
	tile31.create(32, 32);
	tile32.create(32, 32);
	tile33.create(32, 32);
	tile34.create(32, 32);
	tile35.create(32, 32);
	tile36.create(32, 32);
	tile37.create(32, 32);
	tile38.create(32, 32);
	tile39.create(32, 32);
	tile40.create(32, 32);
	tile41.create(32, 32);
	tile42.create(32, 32);
	tile43.create(32, 32);
	tile44.create(32, 32);
	tile45.create(32, 32);
	tile46.create(32, 32);
	tile47.create(32, 32);
	tile48.create(32, 32);
	tile49.create(32, 32);
	tile50.create(32, 32);
	tile51.create(32, 32);
	tile52.create(32, 32);
	tile53.create(32, 32);
	tile54.create(32, 32);
	tile55.create(32, 32);
	tile56.create(32, 32);
	tile57.create(32, 32);
	tile58.create(32, 32);
	tile59.create(32, 32);
	tile60.create(32, 32);
	tile61.create(32, 32);
	tile62.create(32, 32);
	tile63.create(32, 32);
	tile64.create(32, 32);
	tile65.create(32, 32);
	tile66.create(32, 32);
	tile67.create(32, 32);
	tile68.create(32, 32);
	tile69.create(32, 32);
	tile70.create(32, 32);
	tile71.create(32, 32);
	tile72.create(32, 32);
	tile73.create(32, 32);
	tile74.create(32, 32);
	tile75.create(32, 32);
	tile76.create(32, 32);
	tile77.create(32, 32);
	tile78.create(32, 32);
	tile79.create(32, 32);
	tile80.create(32, 32);
	tile81.create(32, 32);
	tile82.create(32, 32);
	tile83.create(32, 32);
	tile84.create(32, 32);
	tile85.create(32, 32);
	tile86.create(32, 32);
	tile87.create(32, 32);
	tile88.create(32, 32);

	tile1.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, 0, this->tileWidth, this->tileHeight), true);
	tile2.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, 0, this->tileWidth, this->tileHeight), true);
	tile3.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, 0, this->tileWidth, this->tileHeight), true);
	tile4.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, 0, this->tileWidth, this->tileHeight), true);
	
	tile5.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile6.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile7.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, this->tileHeight, this->tileWidth, this->tileHeight), true);
	tile8.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, this->tileHeight, this->tileWidth, this->tileHeight), true);
	
	tile9.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*2, this->tileWidth, this->tileHeight), true);
	tile10.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*2, this->tileWidth, this->tileHeight), true);
	tile11.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*2, this->tileWidth, this->tileHeight), true);
	tile12.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*2, this->tileWidth, this->tileHeight), true);
	
	tile13.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*3, this->tileWidth, this->tileHeight), true);
	tile14.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*3, this->tileWidth, this->tileHeight), true);
	tile15.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*3, this->tileWidth, this->tileHeight), true);
	tile16.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*3, this->tileWidth, this->tileHeight), true);
	
	tile17.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*4, this->tileWidth, this->tileHeight), true);
	tile18.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*4, this->tileWidth, this->tileHeight), true);
	tile19.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*4, this->tileWidth, this->tileHeight), true);
	tile20.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*4, this->tileWidth, this->tileHeight), true);
	
	tile21.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*5, this->tileWidth, this->tileHeight), true);
	tile22.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*5, this->tileWidth, this->tileHeight), true);
	tile23.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*5, this->tileWidth, this->tileHeight), true);
	tile24.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*5, this->tileWidth, this->tileHeight), true);
	
	tile25.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*6, this->tileWidth, this->tileHeight), true);
	tile26.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*6, this->tileWidth, this->tileHeight), true);
	tile27.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*6, this->tileWidth, this->tileHeight), true);
	tile28.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*6, this->tileWidth, this->tileHeight), true);
	
	tile29.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*7, this->tileWidth, this->tileHeight), true);
	tile30.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*7, this->tileWidth, this->tileHeight), true);
	tile31.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*7, this->tileWidth, this->tileHeight), true);
	tile32.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*7, this->tileWidth, this->tileHeight), true);
	
	tile33.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*8, this->tileWidth, this->tileHeight), true);
	tile34.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*8, this->tileWidth, this->tileHeight), true);
	tile35.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*8, this->tileWidth, this->tileHeight), true);
	tile36.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*8, this->tileWidth, this->tileHeight), true);
	
	tile37.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*9, this->tileWidth, this->tileHeight), true);
	tile38.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*9, this->tileWidth, this->tileHeight), true);
	tile39.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*9, this->tileWidth, this->tileHeight), true);
	tile40.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*9, this->tileWidth, this->tileHeight), true);
	
	tile41.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*10, this->tileWidth, this->tileHeight), true);
	tile42.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*10, this->tileWidth, this->tileHeight), true);
	tile43.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*10, this->tileWidth, this->tileHeight), true);
	tile44.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*10, this->tileWidth, this->tileHeight), true);
	
	tile45.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*11, this->tileWidth, this->tileHeight), true);
	tile46.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*11, this->tileWidth, this->tileHeight), true);
	tile47.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*11, this->tileWidth, this->tileHeight), true);
	tile48.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*11, this->tileWidth, this->tileHeight), true);
	
	tile49.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*12, this->tileWidth, this->tileHeight), true);
	tile50.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*12, this->tileWidth, this->tileHeight), true);
	tile51.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*12, this->tileWidth, this->tileHeight), true);
	tile52.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*12, this->tileWidth, this->tileHeight), true);
	
	tile53.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*13, this->tileWidth, this->tileHeight), true);
	tile54.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*13, this->tileWidth, this->tileHeight), true);
	tile55.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*13, this->tileWidth, this->tileHeight), true);
	tile56.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*13, this->tileWidth, this->tileHeight), true);
	
	tile57.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*14, this->tileWidth, this->tileHeight), true);
	tile58.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*14, this->tileWidth, this->tileHeight), true);
	tile59.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*14, this->tileWidth, this->tileHeight), true);
	tile60.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*14, this->tileWidth, this->tileHeight), true);
	
	tile61.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*15, this->tileWidth, this->tileHeight), true);
	tile62.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*15, this->tileWidth, this->tileHeight), true);
	tile63.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*15, this->tileWidth, this->tileHeight), true);
	tile64.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*15, this->tileWidth, this->tileHeight), true);
	
	tile65.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*16, this->tileWidth, this->tileHeight), true);
	tile66.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*16, this->tileWidth, this->tileHeight), true);
	tile67.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*16, this->tileWidth, this->tileHeight), true);
	tile68.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*16, this->tileWidth, this->tileHeight), true);
	
	tile69.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*17, this->tileWidth, this->tileHeight), true);
	tile70.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*17, this->tileWidth, this->tileHeight), true);
	tile71.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*17, this->tileWidth, this->tileHeight), true);
	tile72.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*17, this->tileWidth, this->tileHeight), true);
	
	tile73.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*18, this->tileWidth, this->tileHeight), true);
	tile74.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*18, this->tileWidth, this->tileHeight), true);
	tile75.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*18, this->tileWidth, this->tileHeight), true);
	tile76.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*18, this->tileWidth, this->tileHeight), true);
	
	tile77.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*19, this->tileWidth, this->tileHeight), true);
	tile78.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*19, this->tileWidth, this->tileHeight), true);
	tile79.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*19, this->tileWidth, this->tileHeight), true);
	tile80.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*19, this->tileWidth, this->tileHeight), true);
	
	tile81.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*20, this->tileWidth, this->tileHeight), true);
	tile82.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*20, this->tileWidth, this->tileHeight), true);
	tile83.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*20, this->tileWidth, this->tileHeight), true);
	tile84.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*20, this->tileWidth, this->tileHeight), true);
	
	tile85.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(0, (this->tileHeight)*21, this->tileWidth, this->tileHeight), true);
	tile86.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect(this->tileWidth, (this->tileHeight)*21, this->tileWidth, this->tileHeight), true);
	tile87.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*2, (this->tileHeight)*21, this->tileWidth, this->tileHeight), true);
	tile88.copy(this->file_manager->background_tileset, 0, 0, sf::IntRect((this->tileWidth)*3, (this->tileHeight)*21, this->tileWidth, this->tileHeight), true);
	
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
				case 5:
					this->texture->update(tile5, x * 32, y * 32);
					break;
				case 6:
					this->texture->update(tile6, x * 32, y * 32);
					break;
				case 7:
					this->texture->update(tile7, x * 32, y * 32);
					break;
				case 8:
					this->texture->update(tile8, x * 32, y * 32);
					break;
				case 9:
					this->texture->update(tile9, x * 32, y * 32);
					break;
				case 10:
					this->texture->update(tile10, x * 32, y * 32);
					break;
				case 11:
					this->texture->update(tile11, x * 32, y * 32);
					break;
				case 12:
					this->texture->update(tile12, x * 32, y * 32);
					break;
				case 13:
					this->texture->update(tile13, x * 32, y * 32);
					break;
				case 14:
					this->texture->update(tile14, x * 32, y * 32);
					break;
				case 15:
					this->texture->update(tile15, x * 32, y * 32);
					break;
				case 16:
					this->texture->update(tile16, x * 32, y * 32);
					break;
				case 17:
					this->texture->update(tile17, x * 32, y * 32);
					break;
				case 18:
					this->texture->update(tile18, x * 32, y * 32);
					break;
				case 19:
					this->texture->update(tile19, x * 32, y * 32);
					break;
				case 20:
					this->texture->update(tile20, x * 32, y * 32);
					break;
				case 21:
					this->texture->update(tile21, x * 32, y * 32);
					break;
				case 22:
					this->texture->update(tile22, x * 32, y * 32);
					break;
				case 23:
					this->texture->update(tile23, x * 32, y * 32);
					break;
				case 24:
					this->texture->update(tile24, x * 32, y * 32);
					break;
				case 25:
					this->texture->update(tile25, x * 32, y * 32);
					break;
				case 26:
					this->texture->update(tile26, x * 32, y * 32);
					break;
				case 27:
					this->texture->update(tile27, x * 32, y * 32);
					break;
				case 28:
					this->texture->update(tile28, x * 32, y * 32);
					break;
				case 29:
					this->texture->update(tile29, x * 32, y * 32);
					break;
				case 30:
					this->texture->update(tile30, x * 32, y * 32);
					break;
				case 31:
					this->texture->update(tile31, x * 32, y * 32);
					break;
				case 32:
					this->texture->update(tile32, x * 32, y * 32);
					break;
				case 33:
					this->texture->update(tile33, x * 32, y * 32);
					break;
				case 34:
					this->texture->update(tile34, x * 32, y * 32);
					break;
				case 35:
					this->texture->update(tile35, x * 32, y * 32);
					break;
				case 36:
					this->texture->update(tile36, x * 32, y * 32);
					break;
				case 37:
					this->texture->update(tile37, x * 32, y * 32);
					break;
				case 38:
					this->texture->update(tile38, x * 32, y * 32);
					break;
				case 39:
					this->texture->update(tile39, x * 32, y * 32);
					break;
				case 40:
					this->texture->update(tile40, x * 32, y * 32);
					break;
				case 41:
					this->texture->update(tile41, x * 32, y * 32);
					break;
				case 42:
					this->texture->update(tile42, x * 32, y * 32);
					break;
				case 43:
					this->texture->update(tile43, x * 32, y * 32);
					break;
				case 44:
					this->texture->update(tile44, x * 32, y * 32);
					break;
				case 45:
					this->texture->update(tile45, x * 32, y * 32);
					break;
				case 46:
					this->texture->update(tile46, x * 32, y * 32);
					break;
				case 47:
					this->texture->update(tile47, x * 32, y * 32);
					break;
				case 48:
					this->texture->update(tile48, x * 32, y * 32);
					break;
				case 49:
					this->texture->update(tile49, x * 32, y * 32);
					break;
				case 50:
					this->texture->update(tile50, x * 32, y * 32);
					break;
				case 51:
					this->texture->update(tile51, x * 32, y * 32);
					break;
				case 52:
					this->texture->update(tile52, x * 32, y * 32);
					break;
				case 53:
					this->texture->update(tile53, x * 32, y * 32);
					break;
				case 54:
					this->texture->update(tile54, x * 32, y * 32);
					break;
				case 55:
					this->texture->update(tile55, x * 32, y * 32);
					break;
				case 56:
					this->texture->update(tile56, x * 32, y * 32);
					break;
				case 57:
					this->texture->update(tile57, x * 32, y * 32);
					break;
				case 58:
					this->texture->update(tile58, x * 32, y * 32);
					break;
				case 59:
					this->texture->update(tile59, x * 32, y * 32);
					break;
				case 60:
					this->texture->update(tile60, x * 32, y * 32);
					break;
				case 61:
					this->texture->update(tile61, x * 32, y * 32);
					break;
				case 62:
					this->texture->update(tile62, x * 32, y * 32);
					break;
				case 63:
					this->texture->update(tile63, x * 32, y * 32);
					break;
				case 64:
					this->texture->update(tile64, x * 32, y * 32);
					break;
				case 65:
					this->texture->update(tile65, x * 32, y * 32);
					break;
				case 66:
					this->texture->update(tile66, x * 32, y * 32);
					break;
				case 67:
					this->texture->update(tile67, x * 32, y * 32);
					break;
				case 68:
					this->texture->update(tile68, x * 32, y * 32);
					break;
				case 69:
					this->texture->update(tile69, x * 32, y * 32);
					break;
				case 70:
					this->texture->update(tile70, x * 32, y * 32);
					break;
				case 71:
					this->texture->update(tile71, x * 32, y * 32);
					break;
				case 72:
					this->texture->update(tile72, x * 32, y * 32);
					break;
				case 73:
					this->texture->update(tile73, x * 32, y * 32);
					break;
				case 74:
					this->texture->update(tile74, x * 32, y * 32);
					break;
				case 75:
					this->texture->update(tile75, x * 32, y * 32);
					break;
				case 76:
					this->texture->update(tile76, x * 32, y * 32);
					break;
				case 77:
					this->texture->update(tile77, x * 32, y * 32);
					break;
				case 78:
					this->texture->update(tile78, x * 32, y * 32);
					break;
				case 79:
					this->texture->update(tile79, x * 32, y * 32);
					break;
				case 80:
					this->texture->update(tile80, x * 32, y * 32);
					break;
				case 81:
					this->texture->update(tile81, x * 32, y * 32);
					break;
				case 82:
					this->texture->update(tile82, x * 32, y * 32);
					break;
				case 83:
					this->texture->update(tile83, x * 32, y * 32);
					break;
				case 84:
					this->texture->update(tile84, x * 32, y * 32);
					break;
				case 85:
					this->texture->update(tile85, x * 32, y * 32);
					break;
				case 86:
					this->texture->update(tile86, x * 32, y * 32);
					break;
				case 87:
					this->texture->update(tile87, x * 32, y * 32);
					break;
				case 88:
					this->texture->update(tile88, x * 32, y * 32);
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

