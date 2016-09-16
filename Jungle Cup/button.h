#pragma once
#include <SFML/Graphics.hpp>
#include "objectgraphics.h"
class button {
	public: 
			button();
			~button();
			button(objectGraphics *); // �������� ������ ������������ ������, � ��� ��� ����������� ���������� �������� � �������
			bool isPress();
			
	private:
		sf::Vector2i mousePosition; // ������� ������� ����� �� ������
		sf::Vector2i Coord;
		int frameX0;	
		int	frameX1;	//	���������� ����� ������
		int	frameY0;	
		int frameY1;	
};