#include "hero.h"

const int maxSizeX = 100;
const int maxSizeY = 20;

hero::hero(int maxHp, int hp) :
	m_maxHp(maxHp), m_hp(hp)
{
	m_pHPSprite = new sf::RectangleShape();
	m_pHPSprite->setFillColor(sf::Color(0, 255, 0, 255));
	m_pHPSprite->setPosition(100, 500);
	m_pHPSprite->setSize(sf::Vector2f(maxSizeX * m_hp / m_maxHp, maxSizeY));

	m_pMaxHPSprite = new sf::RectangleShape();
	m_pMaxHPSprite->setPosition(100, 500);
	m_pMaxHPSprite->setSize(sf::Vector2f(maxSizeX, maxSizeY));
	m_pMaxHPSprite->setOutlineColor(sf::Color::Red);
	m_pMaxHPSprite->setOutlineThickness(2);
}

hero::~hero()
{
	delete m_pHPSprite;
	delete m_pMaxHPSprite;
}

int hero::GetHP(void)
{
	return m_hp;
}

void hero::SetHP(int hp)
{
	m_hp = hp;
	m_pHPSprite->setSize(sf::Vector2f(maxSizeX * m_hp / m_maxHp, maxSizeY));
}
