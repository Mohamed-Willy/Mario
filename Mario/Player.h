#pragma once
#include <SFML/Graphics.hpp>
#include "CustomImage.h"
using namespace sf;
class Player
{
private:
	int animation_state;
	float x_force, y_force;
	float timer;
public:
	CustomImage *mario;
	Player();
	void update(int, CustomImage);
	void draw(RenderWindow&);
	Vector2f position();
	bool isColiding(CustomImage);
};

