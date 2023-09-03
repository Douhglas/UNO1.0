#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Game.h"
#include "Menu.h"

using namespace std;
int main() {
	sf::RenderWindow window(sf::VideoMode(900, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;

	Game game;
	Menu menu(window);


	while (window.isOpen()) {

		sf::Event eve;

		while (window.pollEvent(eve)) {


			if (eve.type == eve.Closed) {
				window.close();
			}
		    if (eve.type == eve.MouseButtonPressed && menu.isButtonPressed(0,window,mouse,eve) ) {

				cout << " the button has been pressed" << endl;
			}

		}

		window.clear();
		menu.drawOptions(&window);
		window.display();
	}




}