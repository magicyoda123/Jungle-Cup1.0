#include "sprite.h"

#include <SFML/Graphics.hpp>

#include "sprite.h"
#include "button.h"

button::button()
{
}

button::button(sprite * buttonGraphics)
{
	Coord = buttonGraphics->curPosition;
	frameX0 = Coord.x;
	frameY0 = Coord.y;
	Coord = buttonGraphics->curResolution;

	frameX1 = frameX0 + Coord.x;
	frameY1 = frameY0 + Coord.y;
}

button::~button()
{
}

bool button::isPress()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // если левая клавиша мыши нажата
	{
		mousePosition = sf::Mouse::getPosition();
		if (mousePosition.x >= frameX0 && mousePosition.x <= frameX1 && mousePosition.y >= frameY0 && mousePosition.y <= frameY1)
		{
			return true;
		}
		else return false;
	}
}