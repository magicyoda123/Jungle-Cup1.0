#pragma once

#include <SFML/Graphics.hpp>

#include "sprite.h"

class button
{
	public: 
		button();
		button(sprite *); // �������� ������ ������������ ������, � ��� ��� ����������� ���������� �������� � �������
		~button();
	
		bool isPress();
			
	private:
		sf::Vector2i mousePosition; // ������� ������� ����� �� ������
		sf::Vector2i Coord;
		int frameX0;	
		int	frameX1;	//	���������� ����� ������
		int	frameY0;	
		int frameY1;	
};