#include <SFML/Graphics.hpp>
#include "CustomImage.h"
#include "Player.h"
#include "Enemy.h"
#include "MainMenu.h"
using namespace sf;

int main()
{
	// Width and hight , Title, Style
	RenderWindow window(VideoMode(800, 800), "Mario", Style::None | Style::Resize);
	
	Player mario;
	Enemy enemy(3, 0);
	Enemy sEnemy(1, 1);
	CustomImage background("background.jpg", 3, 3, 0, 0, 1);
	CustomImage house("house.png", 2, 2, 4200, 230, 1);
	CustomImage blocks("block.png", 0.5, 0.5, 0, 0, 100);	

	for (int i = 0; i < 100; i++)
	{
		blocks.sprites[i].setPosition(i * 100, 700);
	}
	blocks.sprites[5].setScale(0, 0);
	blocks.sprites[10].setScale(0, 0);
	blocks.sprites[15].setScale(0, 0);
	blocks.sprites[30].setScale(0, 0);
	blocks.sprites[40].setScale(0, 0);

	View camera;
	camera.setSize(800, 800);
	camera.setCenter(400, 400);

	MainMenu winMenu(3);

	winMenu.text[0].setString("Congratulations\n	you won!!!");
	winMenu.text[0].setPosition(30, 50);

	winMenu.text[1].setString("Restart");
	winMenu.text[1].setPosition(270, 350);

	winMenu.text[2].setString("Exit");
	winMenu.text[2].setPosition(270, 450);

	MainMenu loseMenu(3);

	loseMenu.text[0].setString("You Lost!!!");
	loseMenu.text[0].setPosition(130, 50);

	loseMenu.text[1].setString("Restart");
	loseMenu.text[1].setPosition(270, 350);

	loseMenu.text[2].setString("Exit");
	loseMenu.text[2].setPosition(270, 450);

	MainMenu mainMenu(3);

	mainMenu.text[0].setString("Super Mario");
	mainMenu.text[0].setPosition(130, 50);

	mainMenu.text[1].setString("Start");
	mainMenu.text[1].setPosition(270, 350);

	mainMenu.text[2].setString("Exit");
	mainMenu.text[2].setPosition(270, 450);

	Mouse mouse;
	/*
		Phases:
			1- Main Menu
			2- Game
			3- Win
			4- Lose
	*/
	int phase = 1;
	while (window.isOpen())
	{
		// Main Menu
		if (phase == 1) {
			Event event;
			while (window.pollEvent(event))
			{
				if (mouse.isButtonPressed(Mouse::Left)) {
					if (mainMenu.text[1].getFillColor() == Color::Cyan) {
						phase = 2;
						continue;
					}
					if (mainMenu.text[2].getFillColor() == Color::Cyan) {
						window.close();
					}
				}
			}
			mainMenu.update(mouse, window);
			window.clear(Color::Black);
			window.draw(background.sprites[0]);
			mainMenu.draw(window);
			window.display();
		}
		// Game
		if (phase == 2) {	
			Event event;
			mario.update(100, blocks);
			enemy.update(0, 600, 950);
			enemy.update(1, 1100, 1400);
			enemy.update(2, 1700, 2200);
			sEnemy.update(0, mario.mario->sprites[0].getPosition().x, mario.mario->sprites[0].getPosition().y);
		
			if (mario.isColiding(house)) {
				phase = 3;
				continue;
			}
			if (mario.isColiding(*enemy.sprite)) {
				phase = 4;
				continue;
			}
			if (mario.mario->sprites[0].getPosition().y > 1000) {
				phase = 4;
				continue;
			}
			 
			if (mario.isColiding(*sEnemy.sprite)) {
				phase = 4;
				continue;
			}
			while (window.pollEvent(event))
			{

			}	

			background.sprites[0].setPosition(mario.position().x - 50, 0);
			camera.setCenter(mario.position().x + 350, 400);
			window.setView(camera);
			window.clear();
			window.draw(background.sprites[0]);
			window.draw(house.sprites[0]);
			
			for (int i = 0; i < 100; i++)
			{
				window.draw(blocks.sprites[i]);
			}
			enemy.draw(window);
			sEnemy.draw(window);
			mario.draw(window);
			window.display();
		}
		// Win
		if (phase == 3) {
			Event event;
			while (window.pollEvent(event))
			{
				if (mouse.isButtonPressed(Mouse::Left)) {
					if (winMenu.text[1].getFillColor() == Color::Cyan) {
						mario.mario->sprites[0].setPosition(50, 600);
						phase = 2;
						continue;
					}
					if (winMenu.text[2].getFillColor() == Color::Cyan) {
						window.close();
					}
				}
			}
			background.sprites[0].setPosition(0, 0);
			camera.setCenter(400, 400);
			window.setView(camera);
			winMenu.update(mouse, window);
			window.clear();
			window.draw(background.sprites[0]);
			winMenu.draw(window);
			window.display();
		}
		// Lose
		if (phase == 4) {
			Event event;
			while (window.pollEvent(event))
			{
				if (mouse.isButtonPressed(Mouse::Left)) {
					if (loseMenu.text[1].getFillColor() == Color::Cyan) {
						mario.mario->sprites[0].setPosition(50, 600);
						phase = 2;
						continue;
					}
					if (loseMenu.text[2].getFillColor() == Color::Cyan) {
						window.close();
					}
				}
			}
			background.sprites[0].setPosition(0, 0);
			camera.setCenter(400, 400);
			window.setView(camera);
			loseMenu.update(mouse, window);
			window.clear();
			window.draw(background.sprites[0]);
			loseMenu.draw(window);
			window.display();
		}
	}

	return 0;
}


