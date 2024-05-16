#include <SFML/Graphics.hpp>
#include <iostream>
#include "GamePlay.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Prueba");
	window.setFramerateLimit(60);
	GamePlay& gp = GamePlay::getInstance();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Key::Escape)
				window.close();
		}
			
		gp.update();

		window.clear();
		window.draw(gp);
		window.display();

	}

	return 0;
}