#include "Player.h"
#include <SFML/Graphics.hpp>
#include "CustomImage.h"
using namespace sf;

Player::Player() {
	mario = new CustomImage("mario.png", 0.5, 0.5, 50, 600, 1);
	mario->setRect(0, 0, 90, 175);
	animation_state = 0;
	y_force = 0;
	timer = 0;
}

void Player::update(int number_of_blocks, CustomImage blocks) {
	timer += 0.01;
	x_force = 0;
	mario->setRect(animation_state, 0, 90, 175);
	if (Keyboard::isKeyPressed(Keyboard::D) && mario->sprites[0].getPosition().y < 613) {
		x_force = 0.5;
		mario->sprites[0].setScale(0.5, 0.5);
		if (timer > 1) {
			animation_state += 90;
			timer = 0;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A) && mario->sprites[0].getPosition().x > 50 && mario->sprites[0].getPosition().y < 613) {
		x_force = -0.5;
		mario->sprites[0].setScale(-0.5, 0.5);
		if (timer > 1)
		{
			animation_state += 90;
			timer = 0;
		}
	}
	if (y_force <= 1) {
		y_force += 0.01;
	}
	for (int i = 0; i < number_of_blocks; i++)
	{
		if (mario->sprites[0].getGlobalBounds().intersects(blocks.sprites[i].getGlobalBounds()) && mario->sprites[0].getPosition().y < 613) {
			y_force = 0;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && y_force == 0) {
		y_force = -2;
	}
	mario->sprites[0].move(x_force, y_force);
	if (animation_state > 180) {
		animation_state = 0;
	}
}

void Player::draw(RenderWindow& window) {
	window.draw(mario->sprites[0]);
}

Vector2f Player::position() {
	return mario->sprites[0].getPosition();
}

bool Player::isColiding(CustomImage colider) {
	for (int i = 0; i < colider.sprites.size(); i++)
	{
		if (mario->sprites[0].getGlobalBounds().intersects(colider.sprites[i].getGlobalBounds())) {
			return true;
		}
	}
	return false;
}