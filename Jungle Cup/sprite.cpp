#include "sprite.h"

#include <SFML/Graphics.hpp>

sprite::sprite()
{
}

sprite::sprite(char pathImage[], int x0, int y0, int x1, int y1, double scaleX, double scaleY, int posX, int posY)
{
	curText.loadFromFile(pathImage);
	curSprite.setTexture(curText);
	curSprite.setScale(scaleX, scaleY);
	curSprite.setPosition(posX,posY);
	curPosition.x = posX;
	curPosition.y = posY;
	curResolution.x = x1*scaleX;
	curResolution.y = y1*scaleY;
}

sprite::~sprite()
{
}

sf::Sprite sprite::getSprite()
{
	return curSprite;
}
