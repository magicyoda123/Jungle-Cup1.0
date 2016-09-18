#include "animation.h"

#include <SFML/Graphics.hpp>

#include "sprite.h"

animation::animation()
{
}

animation::animation(sprite* spriteSheet, int frameDelay, int numbersOfFrame, sf::RenderWindow* window)
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

animation::~animation()
{
	delete[] spriteSheet_local;
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
void animation::move(int x, int y)
{
	for (int i = 0; i <= m_numberOfFrames; i++)
	{
		spriteSheet_local[i].move(x, y);
	}
}