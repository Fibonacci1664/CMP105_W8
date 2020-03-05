#include "Ball.h"

Ball::Ball()
{
	m_stepVel = sf::Vector2f(-200, 0);
}

Ball::~Ball()
{

}

void Ball::handleInput(float dt)
{

}

void Ball::update(float dt)
{
	move(dt);
}

void Ball::move(float dt)
{
	//if(((getPosition().x - (getSize().x / 2.0f)) < 0) && (m_stepVel.x < 0))
	float realX = getPosition().x;// - (getSize().x / 2.0f);
	if ((realX < 0) && (m_stepVel.x < 0))
	{
		m_stepVel.x = -m_stepVel.x;
		std::cout << getPosition().x << " " << getSize().x;
	}

	/*if ((getPosition().x > + getSize().x / 2.0f > window->getSize().x) && (m_stepVel.x > 0))
	{
		m_stepVel.x = -m_stepVel.x;
	}*/

	setPosition(sf::Vector2f(getPosition().x + (m_stepVel.x * dt), getPosition().y + (m_stepVel.y * dt)));
}