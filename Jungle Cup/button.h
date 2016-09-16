#pragma once
#include <SFML/Graphics.hpp>
#include "objectgraphics.h"
class button {
	public: 
			button();
			~button();
			button(objectGraphics *); // передаем объект графического класса, в нем уже содержиться разрешение картинки и масштаб
			bool isPress();
			
	private:
		sf::Vector2i mousePosition; // позиция курсора мышки на экране
		sf::Vector2i Coord;
		int frameX0;	
		int	frameX1;	//	координаты рамки кнопки
		int	frameY0;	
		int frameY1;	
};