#include <SFML/Graphics.hpp>
#include <windows.h>

#include "sprite.h"
#include "animation.h"
#include "button.h"
#include "hero.h"

int main()
{
	// узнаем разрешение экрана
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int startGaming = 0;

	// Полный экран
	//sf::RenderWindow window(sf::VideoMode(screenWidth / 2, screenHeight / 2), "Jungle Cup", sf::Style::Fullscreen);

	// Запуск в окне
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Jungle Cup");

	//	задний фон меню спрайт и текстура
	
	sf::Sprite spriteBackground;
	sf::Sprite spriteNewGame;
	sf::Sprite spriteLevel1;
	
	//	загрузка текстуры из файла. текстура размера самой картинки. присваиваем текстуру спрайту. задаем масштаб
	sprite background("./Resources/sprites/picture.jpg", 0, 0, 1400, 1082, 1.37, 1, 0, 0);
	sprite newGame("./Resources/sprites/newgame.png", 0, 0, 200, 50, 1, 1, screenWidth / 2, screenHeight / 2);
	sprite level1("./Resources/sprites/Jungle-Level_site.png", 0, 0, 900, 473, 1.5, 1.5, 0, 0);

	sprite animGiraffe1("./Resources/sprites/giraffe/frame1.png", 0, 0, 192, 260, 1, 1, 200, 200);
	sprite animGiraffe2("./Resources/sprites/giraffe/frame2.png", 0, 0, 192, 260, 1, 1, 200, 200);
	sprite animGiraffe3("./Resources/sprites/giraffe/frame3.png", 0, 0, 192, 260, 1, 1, 200, 200);
	sprite animGiraffe4("./Resources/sprites/giraffe/frame4.png", 0, 0, 192, 260, 1, 1, 200, 200);
	sprite anim_hero[] = {
		animGiraffe1,
		animGiraffe2,
		animGiraffe3,
		animGiraffe4
	};
	animation* pGiraffeAnimation = new animation(anim_hero, 25, sizeof(anim_hero) / sizeof(anim_hero[0]), &window);
	hero* pHero = new hero(100, 80);

	spriteBackground = background.getSprite();
	spriteNewGame = newGame.getSprite();
	spriteLevel1 = level1.getSprite();

	button buttonNewGame(&newGame);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				pGiraffeAnimation->move(screenWidth/100,0);
			}
		}
	
		if (buttonNewGame.isPress() == true)
		{
			startGaming = 1;
		}
		
		switch (startGaming)
		{
		case 0:
			window.draw(spriteBackground);
			window.draw(spriteNewGame);
			break;
		case 1:
			window.draw(spriteLevel1);
			pGiraffeAnimation->play();
			pHero->SetHP(pHero->GetHP() - 1);
			window.draw(*(pHero->GetMaxHPSprite()));
			window.draw(*(pHero->GetSprite()));
			break;
		default:
			break;
		}
		window.display();
		window.clear();
	}

	return 0;
}