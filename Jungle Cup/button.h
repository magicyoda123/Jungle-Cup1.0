#pragma once

#include <SFML/Graphics.hpp>

#include "sprite.h"

class button
{
	public: 
		button();
		button(sprite *); // передаем объект графического класса, в нем уже содержиться разрешение картинки и масштаб
		~button();
	
		bool isPress();
			
	private:
		sf::Vector2i mousePosition; // позиция курсора мышки на экране
		sf::Vector2i Coord;
		int frameX0;	
		int	frameX1;	//	координаты рамки кнопки
		int	frameY0;	
		int frameY1;	
};