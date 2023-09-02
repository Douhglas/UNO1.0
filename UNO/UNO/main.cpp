#include <iostream>

#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;
int main() {
	sf::RenderWindow window(sf::VideoMode(900, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;

	sf::RectangleShape button;
	button.setSize(sf::Vector2f(200, 300));
	button.setPosition(sf::Vector2f(400, 600));
	Game Option;


	while (window.isOpen()) {

		sf::Event eve;

		while (window.pollEvent(eve)) {


			if (eve.type == eve.Closed) {
				window.close();
			}
			if (eve.type == eve.MouseButtonPressed && Option.isButtonPressed(button, window, mouse, eve)) {

				cout << " the button has been pressed" << endl;
			}

		}

		window.clear();
		window.draw(button);
		window.display();
	}




}