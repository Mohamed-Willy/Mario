#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include "CustomImage.h"
using namespace sf;

Enemy::Enemy(int count, int type) {
	this->type = type;
	if (type == 0) {
		sprite = new CustomImage("m.png", 0.3, 0.3, 600, 650, count);
	}
	if (type == 1) {
		sprite = new CustomImage("r.png", 0.3, 0.3, 0, 0, count);
	}
	bool cur = 1;
	for (int i = 0; i < count; i++)
	{
		enemy_direction.push_back(cur);
	}
}

void Enemy::update(int index, float start, float end) {
	if (type == 0) {
		if (sprite->sprites[index].getPosition().x <= start) {
			sprite->sprites[index].setPosition(start, sprite->sprites[index].getPosition().y);
			enemy_direction[index] = 1;
		}
		if (sprite->sprites[index].getPosition().x >= end) {
			enemy_direction[index] = 0;
		}
		if (enemy_direction[index] == 1) {
			sprite->sprites[index].move(0.1, 0);
		}
		else {
			sprite->sprites[index].move(-0.1, 0);
		}
	}
	if (type == 1) {
		// start -> mario xpositon 
		// end -> mario yposition
		if (sprite->sprites[index].getPosition().x < start) {
			enemy_direction[index] = 1;
		}
		else {
			enemy_direction[index] = 0;
		}
		if (sprite->sprites[index].getPosition().y <= end) {
			y_direction = 1;
		}
		else {
			y_direction = 0;
		}
		sprite->sprites[index].move(0.1 * enemy_direction[index] + -0.1 * (1 - enemy_direction[index]), 0.1 * y_direction + -0.1 * (1 - y_direction));
		if (enemy_direction[index] == 0 && sprite->sprites[index].getPosition().x > start + 0.1)
		{
			sprite->sprites[index].setScale(-0.3, 0.3);
		}
		else if(sprite->sprites[index].getPosition().x < start - 0.1){
			sprite->sprites[index].setScale(0.3, 0.3);
		}
	}
	
}

void Enemy::draw(RenderWindow& window) {
	for (int i = 0; i < sprite->sprites.size(); i++)
	{
		window.draw(sprite->sprites[i]);
	}
}
