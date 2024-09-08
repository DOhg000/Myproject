#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.cpp"

using namespace sf;

bool up = false;
bool down = false;
bool left = false;
bool right = false;


int main()
{
	RenderWindow window(VideoMode(1000, 600), "Leesson");
	Player player;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				player.processEvents(event.key.code, true);
			if (event.type == Event::KeyReleased)
				player.processEvents(event.key.code, false);
		}
		window.clear();
		player.update();
		player.drawTo(window);
		window.display();
	}

}


