#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_BallShape.setSize(sf::Vector2f(10, 10));
	m_BallShape.setPosition(m_Position);
}

FloatRect Ball::getPosition()
{
	return m_BallShape.getGlobalBounds();
}

float Ball::getXVelocity()
{
	return m_DirectionX;
}

// Reverse the ball
void Ball::reboundBat()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBottom()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundTop()
{
	m_DirectionY = -m_DirectionY;
}


RectangleShape Ball::getBallShape()
{
	return m_BallShape;
}

void Ball::update(Time dt)
{
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	m_BallShape.setPosition(m_Position);
}