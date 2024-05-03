#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_BatShape.setSize(sf::Vector2f(50, 5));
	m_BatShape.setRotation(90.f);
	m_BatShape.setPosition(m_Position);
}


FloatRect Bat::getPosition()
{
	return m_BatShape.getGlobalBounds();
}

RectangleShape Bat::getBatShape()
{
	return m_BatShape;
}

void Bat::moveUp()
{
	m_MovingUp = true;
}

void Bat::moveDown()
{
	m_MovingDown = true;
}

void Bat::stopUp()
{
	m_MovingUp = false;
}

void Bat::stopDown()
{
	m_MovingDown = false;
}

void Bat::update(Time dt)
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