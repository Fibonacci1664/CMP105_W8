#pragma once
#include"Framework\GameObject.h"
#include <iostream>
class Ball : public GameObject
{
public :
	Ball();
	~Ball();

	void handleInput(float dt) override;
	void update(float dt) override;
	void move(float dt);

private:
	sf::Vector2f m_stepVel;
};

