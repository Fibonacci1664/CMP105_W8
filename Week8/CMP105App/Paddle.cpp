#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
	velocity = sf::Vector2f(0, 10000);
}

Paddle::~Paddle()
{

}

void Paddle::handleInput(float dt)
{
	// If the position of our paddle is greater than the middle of the window, then it must be the RIGHT paddle.
	if (getPosition().x > 600)
	{
		// Scrolled the wheel UP = positive number. move paddle up
		if (input->getMouseWheelDelta() > 0)
		{
			// This is essentially the same as a 'Force up'.
			input->setMouseWheelDelta(0);
			//std::cout << "Scrolled the wheel up!\n";
			setPosition(getPosition().x, getPosition().y - (velocity.y * dt));			
		}

		// Scrolled the wheel DOWN = negative number. move paddle down
		if (input->getMouseWheelDelta() < 0)
		{	
			input->setMouseWheelDelta(0);
			//std::cout << "Scrolled the wheel down!\n";
			setPosition(getPosition().x, getPosition().y + (velocity.y * dt));
		}
	}

	// If the position of our paddle is less than the middle of the window, then it must be the LEFT paddle.
	if (getPosition().x < 600)
	{
		// Move paddle up.
		if (input->isKeyDown(sf::Keyboard::W))
		{
			setPosition(getPosition().x, getPosition().y - ((velocity.y / 12.0f ) * dt));
		}

		// Move paddle down.
		if (input->isKeyDown(sf::Keyboard::S))
		{
			setPosition(getPosition().x, getPosition().y + ((velocity.y / 12.0f) * dt));
		}
	}	
}

void Paddle::update(float dt)
{
	checkScreenBounds();
}

void Paddle::checkScreenBounds()
{
	// Check paddle against top of window.
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
	}

	// Check paddle against bottom of the window.
	if (getPosition().y + getSize().y > window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y);
	}
}