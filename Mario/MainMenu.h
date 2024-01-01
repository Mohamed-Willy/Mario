#pragma once
#include <SFML/Graphics.hpp>
#include "CustomImage.h"
using namespace sf;
class MainMenu
{
private:
	Font font;
public:
	vector<Text> text;
	MainMenu(int);
	void draw(RenderWindow&);
	void update(Mouse, RenderWindow&);
};

