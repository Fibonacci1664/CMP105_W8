#include "Ball.h"

Ball::Ball()
{
	setVelocity(sf::Vector2f(105, 0));
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
	// Check left bounds.
	if(((getPosition().x - (getSize().x / 2.0f)) < 0) && (velocity.x < 0))
	{
		velocity.x = -velocity.x;
	}

	// Check right bounds.
	if (((getPosition().x + (getSize().x / 2.0f )) > window->getSize().x) && (velocity.x > 0))
	{
		velocity.x = -velocity.x;
	}

	setPosition(sf::Vector2f(getPosition().x + (velocity.x * dt), getPosition().y + (velocity.y * dt)));
}