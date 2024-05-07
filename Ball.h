#pragma once
#include <SFML/Graphics.hpp>
#include "Bat.h"

using namespace sf;

class Ball
{
private:
	Vector2f m_Position;
	RectangleShape m_BallShape;

	float m_Speed = 2000.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getBallShape();

	float getXVelocity();

	void reboundBat();

	void reboundTop();

	void reboundBottom();

	void pointP1(Bat* bat);

	void pointP2(Bat* bat);

	void update(Time dt);
};