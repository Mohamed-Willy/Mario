#include "MainMenu.h"
#include <SFML/Graphics.hpp>
#include "CustomImage.h"
using namespace sf;

MainMenu::MainMenu(int numOfWords) {
	font.loadFromFile("font.ttf");
	Text temp;
	temp.setFont(font);
	temp.setFillColor(Color::White);
	temp.setCharacterSize(100);
	for (int i = 0; i < numOfWords; i++)
	{
		text.push_back(temp);
		temp.setCharacterSize(50);
	}
}

void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < text.size(); i++)
	{
		window.draw(text[i]);
	}
}

void MainMenu::update(Mouse mouse, RenderWindow& window) {
	for (int i = 1; i < text.size(); i++)
	{
		text[i].setFillColor(Color::White);
		float x = text[i].getPosition().x + text[i].getGlobalBounds().width;
		float y = text[i].getPosition().y + text[i].getGlobalBounds().height;
		if (
			mouse.getPosition(window).x > text[i].getPosition().x && mouse.getPosition(window).x < x
			&& mouse.getPosition(window).y > text[i].getPosition().y && mouse.getPosition(window).y < y) {
			text[i].setFillColor(Color::Cyan);
		}
	}
}