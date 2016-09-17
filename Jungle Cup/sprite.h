#pragma once

#include <SFML/Graphics.hpp>

#include <string>

class sprite
{
public: 
	sprite();
	sprite(char pathImage[], int x0, int y0, int x1, int y1, double scaleX, double scaleY, int posX, int posY);
	~sprite();

	sf::Sprite getSprite();
	sf::Texture curText;
	sf::Sprite curSprite;
	sf::Vector2i curResolution;
	sf::Vector2i curPosition;
		
};