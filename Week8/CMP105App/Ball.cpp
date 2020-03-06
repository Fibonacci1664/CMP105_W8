#include "Ball.h"

Ball::Ball()
{
	setVelocity(sf::Vector2f(300, 300));
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
		std::cout << "Player 2 scored a point!\n";
		setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));
		velocity.x = -velocity.x;
	}

	// Check right bounds.
	if ((getPosition().x + getSize().x > window->getSize().x) && (velocity.x > 0))
	{
		std::cout << "Player 1 scored a point!\n";
		setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));
		velocity.x = -velocity.x;
	}

	// Check ball against top of window.
	if (getPosition().y < 0 && velocity.y < 0)
	{
		velocity.y = -velocity.y;
	}

	// Check ball against bottom of window.
	if (getPosition().y + getSize().y > window->getSize().y && velocity.y > 0)
	{
		velocity.y = -velocity.y;
	}

	setPosition(sf::Vector2f(getPosition().x + vel.x, getPosition().y + vel.y));
}