#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "Deck.h"
#include "Game.h"
#include "Menu.h"
#include "Card.h"
using namespace std;
int main() {

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1200, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;
	bool unoWindow = false;

	Card card(&window);
	
	bool isLeftTurn = true;
	int color;
	int numCard;
	bool startGame = false;
	int atLeastOneCard = 0;

		while (window.isOpen()) {

			sf::Event eve;

			while (window.pollEvent(eve)) {


				if (eve.type == eve.Closed) {

					window.close();

				}
				if (eve.type == eve.MouseButtonPressed && card.isButtonPressed(0, window, mouse, eve)) {

					cout << " the button has been pressed" << endl;

				}
				if (eve.type == eve.MouseButtonPressed && card.isButtonPressed(1, window, mouse, eve)) {

					window.close();
					unoWindow = true;
				}

			}

			window.clear();
			card.drawOptions(&window);
			window.display();
		}

		if (unoWindow == true) {

			window.create(sf::VideoMode(1200, 900), "UNO");
			while (window.isOpen())
			{

				sf::Event even;

				color = rand() % 4;
				numCard = rand() % 15;

				while (window.pollEvent(even)) {
					
					if (even.type == even.Closed) {

						window.close();

					}
					if (even.type == even.MouseButtonPressed && card.isButtonPressed(2, window, mouse, even)) {
						card.initPileCard(color,numCard );
						startGame = true;
					}
					if (even.type == even.MouseButtonPressed) {
						if (card.mainDeckIsPressed(window, mouse, even)) {
							card.getTypeCard(color, numCard, isLeftTurn);
						}
					}
					if (even.type == even.KeyPressed) {
						if (even.key.code == sf::Keyboard::Enter) {
							if (isLeftTurn == true && atLeastOneCard != 0) {
								isLeftTurn = false;
								atLeastOneCard = 0;
							}
							if (isLeftTurn == false && atLeastOneCard !=0) {
								isLeftTurn = true;
								atLeastOneCard = 0;
							}
						}
					}
					if (even.type == even.KeyPressed) {
						if (even.key.code == sf::Keyboard::A) {
							card.printPileColorAnsNUmber();
						}
					}
					if (even.type == even.MouseButtonPressed) {
						for (int i = 0; i < 20; i++) {
							if (card.playerDeckIsPressed(isLeftTurn,i,window, mouse, even)) {
								card.checkValidCard(i, isLeftTurn, atLeastOneCard);
								
							}
						}
					}
				}

				window.clear();

				if (startGame) {
					card.drawDecks(&window);
				}
				else {
					card.drawOptions(1, &window);
				}

				window.display();

			}
		}
}