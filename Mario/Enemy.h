#pragma once
#include <SFML/Graphics.hpp>
#include "CustomImage.h"
using namespace sf;
class Enemy
{
private:
	vector<bool> enemy_direction; // 1 -> right, 0 -> left
	bool y_direction;
	int type;

public:
	CustomImage *sprite;
	Enemy(int, int);
	void update(int, float, float);
	void draw(RenderWindow& window);

};

