#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	loadTextures();
	initBoundShapes();
	initBalls();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	m_ball_1.update(dt);
	m_ball_2.update(dt);

	/*if (Collision::checkBoundingCircle(&m_ball_1, &m_ball_2))
	{
		m_ball_1.collisionResponse(&m_ball_2);
		m_ball_2.collisionResponse(&m_ball_1);
	}*/

	if (Collision::checkBoundingBox(&m_ball_1, &m_ball_2))
	{
		m_ball_1.collisionResponse(&m_ball_2);
		m_ball_2.collisionResponse(&m_ball_1);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	//window->draw(m_circleBounds);
	//window->draw(m_ball_1.getCollisionBox());
	window->draw(m_ball_1);
	window->draw(m_ball_2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

void Level::loadTextures()
{
	if (!m_ballTexture.loadFromFile("gfx/Beach_ball.png"))
	{
		std::cerr << "Error loading file!\n";
	}
}

void Level::initBoundShapes()
{
	/*m_circleBounds.setRadius(40.0f);
	m_circleBounds.setFillColor(sf::Color(126, 126, 126, 0));
	m_circleBounds.setOutlineColor(sf::Color::Red);
	m_circleBounds.setOutlineThickness(2.0f);
	m_circleBounds.setPosition(m_ball_1.getPosition());*/

	
}

void Level::initBalls()
{
	// Place ball in middle of screen on the left hand side.
	m_ball_1.setInput(input);
	m_ball_1.setWindow(window);
	m_ball_1.setTexture(&m_ballTexture);
	m_ball_1.setSize(sf::Vector2f(80, 80));
	//m_ball_1.setOrigin(sf::Vector2f(m_ball_1.getSize().x / 2.0f, m_ball_1.getSize().y / 2.0f));
	m_ball_1.setPosition(0, window->getSize().y / 2.0f);
	m_ball_1.setOutlineColor(sf::Color::Red);
	m_ball_1.setOutlineThickness(2.0f);

	m_ball_1.setCollisionBox(sf::FloatRect(0, 0, 80, 80));
	//m_ball_1.setCollisionBox(m_ball_1.getPosition().x - m_ball_1.getSize().x / 2.0f, m_ball_1.getPosition().y - m_ball_1.getSize().y / 2.0f, m_ball_1.getSize().x, m_ball_1.getSize().y);

	// Place ball in middle of screen on the right hand side.
	m_ball_2.setInput(input);
	m_ball_2.setWindow(window);
	m_ball_2.setTexture(&m_ballTexture);
	m_ball_2.setSize(sf::Vector2f(80, 80));
	//m_ball_2.setOrigin(sf::Vector2f(m_ball_2.getSize().x / 2.0f, m_ball_2.getSize().y / 2.0f));
	m_ball_2.setPosition(window->getSize().x - m_ball_2.getSize().x, window->getSize().y / 2.0f);
	m_ball_2.setOutlineColor(sf::Color::Red);
	m_ball_2.setOutlineThickness(2.0f);

	m_ball_2.setCollisionBox(sf::FloatRect(0, 0, 80, 80));
	//m_ball_2.setCollisionBox(m_ball_2.getPosition().x - m_ball_2.getSize().x / 2.0f, m_ball_2.getPosition().y - m_ball_2.getSize().y / 2.0f, m_ball_2.getSize().x, m_ball_2.getSize().y);

}