#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
public:
	void processEvents(Keyboard::Key key, bool checkPressed)
	{
		if (checkPressed == true)
		{
			if (key == Keyboard::W)
				up = true;
			if (key == Keyboard::S)
				down = true;
			if (key == Keyboard::A)
				left = true;
			if (key == Keyboard::D)
				right = true;
		}
		if (checkPressed == false)
		{
			up = false;
			down = false;
			left = false;
			right = false;
		}
		herosprite.setScale(50.f, 50.f);
	}

	void update()
	{
		sf::Vector2f movement;
		float angle = 1.0f;
		if (up) 
			movement.y -= 1.0f;
		if (down)
			movement.y += 1.0f;
		if (left) 
			movement.x -= 1.0f;
		if (right) 
			movement.x += 1.0f;

		herosprite.move(movement);
	}

	void drawTo(RenderWindow &window)
	{
		heroimage.loadFromFile("tank.png");
		herotexture.loadFromImage(heroimage);
		herosprite.setTexture(herotexture);
		window.draw(herosprite);
	}
private:
	Image heroimage;
	Texture herotexture;
	Sprite herosprite;

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};