#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class hero
{
public:
	hero(int maxHp, int hp);
	~hero();

	int GetHP(void);
	void SetHP(int hp);

	sf::RectangleShape* GetSprite(void) { return m_pHPSprite; }
	sf::RectangleShape* GetMaxHPSprite(void) { return m_pMaxHPSprite; }

private:
	int m_hp;
	int m_maxHp;

	sf::RectangleShape* m_pHPSprite;
	sf::RectangleShape* m_pMaxHPSprite;

};