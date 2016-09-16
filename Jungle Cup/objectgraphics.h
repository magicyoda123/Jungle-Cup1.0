#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class objectGraphics
{
public: 
		objectGraphics();
		~objectGraphics();
		objectGraphics(char pathImage[], int x0, int y0, int x1, int y1, double scaleX, double scaleY, int posX, int posY);
		sf::Sprite getSprite();
		sf::Texture curText;
		sf::Sprite curSprite;
		sf::Vector2i curResolution;
		sf::Vector2i curPosition;
		
};