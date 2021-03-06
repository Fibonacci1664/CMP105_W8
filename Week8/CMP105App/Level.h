#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"


class Level
{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	void loadTextures();
	void initBoundShapes();
	void initPaddles();
	void initBalls();

	sf::Texture m_ballTexture;

	Ball m_ball_1;
	//Ball m_ball_2;
	sf::CircleShape m_circleBounds;
	Paddle m_leftPaddle;
	Paddle m_rightPaddle;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};