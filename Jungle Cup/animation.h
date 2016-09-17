#pragma once

#include <SFML/Graphics.hpp>
#include "sprite.h"

class animation
{
public: 
	animation();
	animation(sprite* spriteSheet, int frameDelay, int numbersOfFrame, sf::RenderWindow* window);
	~animation();

	sf::RenderWindow* local_window;
	sf::Sprite spriteSheet_local[10];
	
	void play();
	void stop();

private:
	int m_currentFrame;
	int m_numberOfFrames;

	bool m_isPlaing;
	
};
