#pragma once
#include "animation.h"
#include <SFML/Graphics.hpp>
#include "objectgraphics.h"
animation::~animation()
{
}
animation::animation()
{
}
animation::animation( objectGraphics spriteSheet[], int frameDelay, int numbersOfFrame, sf::RenderWindow &window)
{
	i = 0;
	Frames = numbersOfFrame;
	local_window = &window;
	for (i = 0; i < Frames; i++)
	{
		spriteSheet_local[i] = spriteSheet[i].getSprite();
	}
}
void animation::play()
{
	while (i< Frames)
	{
		local_window->draw(spriteSheet_local[i]);
		i++;
		sf::sleep(sf::milliseconds(25));
	}
}
void animation::stop()
{
	local_window->draw(spriteSheet_local[0]);
}