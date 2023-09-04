#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Deck.h"
#include "Game.h"
#include "Menu.h"
#include "Card.h"
using namespace std;
int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;


	Menu menu(window);

	Deck deck(&window);
	
	

		while (window.isOpen()) {

			sf::Event eve;

			while (window.pollEvent(eve)) {


				if (eve.type == eve.Closed) {

					window.close();

				}
				if (eve.type == eve.MouseButtonPressed && menu.isButtonPressed(0, window, mouse, eve)) {

					cout << " the button has been pressed" << endl;

				}
				if (eve.type == eve.MouseButtonPressed && menu.isButtonPressed(1, window, mouse, eve)) {

					window.close();

				}

			}

			window.clear();
			menu.drawOptions(&window);
			window.display();
		}


		window.create(sf::VideoMode(1200, 900), "UNO");

		while (window.isOpen())
		{
			sf::Event even;

			while (window.pollEvent(even)) {

				if (even.type == even.Closed) {

					window.close();

				}
				if (even.type == even.KeyPressed) {

				}

			}
			

			window.clear();
			deck.drawDecks(&window);
			menu.drawOptions(1, &window);
			window.display();

		}
	
}