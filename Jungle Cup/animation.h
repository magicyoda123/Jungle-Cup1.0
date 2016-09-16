#pragma once
#include <SFML/Graphics.hpp>
#include "objectgraphics.h"
class animation
{
public: 
	animation();
	~animation();
	animation(objectGraphics spriteSheet[], int frameDelay, int numbersOfFrame, sf::RenderWindow &window);
	void play();
	sf::RenderWindow *local_window;
	sf::Sprite spriteSheet_local[10];
	
	void stop();
private:
	int i;
	bool walk;
	int Frames;
	
	
};
