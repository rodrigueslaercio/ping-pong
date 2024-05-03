#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_Position;

	// The Bat itself
	RectangleShape m_BatShape;

	float m_Speed = 1000.0f;

	bool m_MovingUp = false;
	bool m_MovingDown = false;


public:
	Bat(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getBatShape();

	void moveUp();

	void moveDown();

	void stopUp();

	void stopDown();

	void update(Time dt);
};