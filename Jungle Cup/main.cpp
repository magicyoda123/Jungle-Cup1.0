#include <SFML/Graphics.hpp>
#include "objectgraphics.h"
#include "button.h"
#include "animation.h"
#include <windows.h>
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
	objectGraphics background("picture.jpg",0,0,1400,1082,1.37,1,0,0);
	objectGraphics newGame("newgame.png", 0, 0, 200, 50, 1, 1, screenWidth / 2, screenHeight / 2);
	objectGraphics level1("Jungle-Level_site.png",0,0,900,473,1.5,1.5,0,0);

	objectGraphics animGiraffe1("./data/sprites/giraffe/frame1.png", 0, 0, 192, 260, 1, 1, 200, 200);
	objectGraphics animGiraffe2("./data/sprites/giraffe/frame2.png", 0, 0, 192, 260, 1, 1, 200, 200);
	objectGraphics animGiraffe3("./data/sprites/giraffe/frame3.png", 0, 0, 192, 260, 1, 1, 200, 200);
	objectGraphics animGiraffe4("./data/sprites/giraffe/frame4.png", 0, 0, 192, 260, 1, 1, 200, 200);
	objectGraphics anim_hero[4] = {
		animGiraffe1,
		animGiraffe2,
		animGiraffe3,
		animGiraffe4
	};
	animation* pGiraffeAnimation = new animation(anim_hero, 25, 4, &window);

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
		}
	
		if (buttonNewGame.isPress() == true)
		{
			startGaming = 1;
		}
	
		if (startGaming == 0)
		{
			window.draw(spriteBackground);
			window.draw(spriteNewGame);
			window.draw(animGiraffe1.getSprite());
		}
		if (startGaming == 1)
		{
			window.draw(spriteLevel1);
			pGiraffeAnimation->play();
		}
		window.display();
		window.clear();
	}

	return 0;
}