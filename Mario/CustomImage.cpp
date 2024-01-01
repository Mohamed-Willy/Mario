#include "CustomImage.h"
#include <SFML/Graphics.hpp>
using namespace sf;


CustomImage::CustomImage(string texturePath, float scaleX, float scaleY, float positionX, float positionY, int num_of_sprites) {
	texture.loadFromFile(texturePath);
	Sprite cur;
	for (int i = 0; i < num_of_sprites; i++)
	{
		cur.setTexture(texture);
		cur.setScale(scaleX, scaleY);
		cur.setPosition(positionX, positionY);
		sprites.push_back(cur);
	}
}

void CustomImage::setRect(float x, float y, float w, float h) {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].setTextureRect(IntRect(x, y, w, h));
	}
}