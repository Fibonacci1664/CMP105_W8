#include "Ball.h"

Ball::Ball()
{
	setVelocity(sf::Vector2f(100, 0));
}

Ball::~Ball()
{

}

void Ball::handleInput(float dt)
{

}

void Ball::update(float dt)
{
	move(velocity * dt);
}

void Ball::move(sf::Vector2f vel)
{
	// Check left bounds.
	if((getPosition().x < 0) && (velocity.x < 0))
	{
		velocity.x = -velocity.x;
	}

	// Check right bounds.
	if ((getPosition().x + getSize().x > window->getSize().x) && (velocity.x > 0))
	{
		velocity.x = -velocity.x;
	}

	setPosition(sf::Vector2f(getPosition().x + vel.x, getPosition().y + vel.y));
}