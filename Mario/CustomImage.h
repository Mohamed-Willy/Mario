#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class CustomImage
{
private:
	Texture texture;
public:
	vector<Sprite> sprites;
	CustomImage(string, float, float, float, float, int);
	void setRect(float x, float y, float w, float h);
};

