#pragma once
#include "Framework/GameObject.h"

class Paddle : public GameObject
{
public:
	Paddle();
	~Paddle();

	void handleInput(float dt) override;
	void update(float dt) override;

private:
	void checkScreenBounds();
};