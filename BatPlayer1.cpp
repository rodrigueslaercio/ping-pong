#include "BatPlayer1.h"

BatPlayer1::BatPlayer1(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_BatShape.setSize(sf::Vector2f(50, 5));
	m_BatShape.setRotation(90.f);
	m_BatShape.setPosition(m_Position);
}


FloatRect BatPlayer1::getPosition()
{
	return m_BatShape.getGlobalBounds();
}

RectangleShape BatPlayer1::getBatShape()
{
	return m_BatShape;
}

void BatPlayer1::moveUp()
{
	m_MovingUp = true;
}

void BatPlayer1::moveDown()
{
	m_MovingDown = true;
}

void BatPlayer1::stopUp()
{
	m_MovingUp = false;
}

void BatPlayer1::stopDown()
{
	m_MovingDown = false;
}

void BatPlayer1::update(Time dt)
{
	if (m_MovingUp)
	{
		m_Position.y -= m_Speed * dt.asSeconds();
	}

	if (m_MovingDown)
	{
		m_Position.y += m_Speed * dt.asSeconds();
	}

	m_BatShape.setPosition(m_Position);
	
}