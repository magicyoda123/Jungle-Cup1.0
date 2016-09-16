#pragma once

#include "animation.h"

#include <SFML/Graphics.hpp>
#include "objectgraphics.h"

animation::animation()
{
}

animation::~animation()
{
}

animation::animation(objectGraphics* spriteSheet, int frameDelay, int numbersOfFrame, sf::RenderWindow* window)
{
	m_currentFrame = 0;
	m_numberOfFrames = numbersOfFrame;
	local_window = window;
	for(int iFrameCounter = 0; iFrameCounter < m_numberOfFrames; iFrameCounter++)
	{
		spriteSheet_local[iFrameCounter] = spriteSheet[iFrameCounter].getSprite();
	}
	m_isPlaing = true;
}

void animation::play()
{
	local_window->draw(spriteSheet_local[m_currentFrame]);
	sf::sleep(sf::milliseconds(250));
		
	if (m_isPlaing)
	{
		m_currentFrame++;
	}
	if (m_currentFrame == m_numberOfFrames) m_currentFrame = 0;

	//if (m_currentFrame == m_numberOfFrames) m_currentFrame = 0;
	//while (m_currentFrame < m_numberOfFrames)
	//{
	//	local_window->draw(spriteSheet_local[m_currentFrame]);
	//	sf::sleep(sf::milliseconds(10000));
	//	
	//	if (m_isPlaing)
	//	{
	//		m_currentFrame++;
	//	}
	//}
}

void animation::stop()
{
	local_window->draw(spriteSheet_local[0]);
	m_isPlaing = false;
}