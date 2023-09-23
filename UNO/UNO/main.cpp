#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "Deck.h"
#include "Game.h"
#include "Menu.h"
#include "Card.h"


// init 8 cards per deck
//change buttons texture
//UNO button

using namespace std;
int main() {

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1200, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;
	bool unoWindow = false;

	Card card(&window);
	
	bool isLeftTurn = true;
	int CardsOfTheSameNumberPerTurn = 0;
	int pluscCardLimitperTurn = 0;
	int plusCardStatement = 0;
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
				card.checkStatementColorChange();
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
							if ((isLeftTurn == true && atLeastOneCard != 0) && card.isNotCardsToEat() == true ||
							((isLeftTurn == true && atLeastOneCard != 0) && (card.getPile().getNumber() == 12 || card.getPile().getNumber() == 16))){

								isLeftTurn = false;
								atLeastOneCard = 0;
								CardsOfTheSameNumberPerTurn = 0;
								
								card.checkZeroCardStatement();
								card.checklimitPlusCard(pluscCardLimitperTurn);
								card.checkStatementPlusCard(pluscCardLimitperTurn);
								if (card.getPile().getNumber() == 10 || card.getPile().getNumber() == 11) {
									card.checkLostTurnCard(isLeftTurn);
								}
						
							}
							if ((isLeftTurn == false && atLeastOneCard != 0)&& card.isNotCardsToEat() == true ||
							((isLeftTurn == false && atLeastOneCard != 0) && (card.getPile().getNumber() == 12 || card.getPile().getNumber() == 16))){

								isLeftTurn = true;
								CardsOfTheSameNumberPerTurn = 0;
								atLeastOneCard = 0;

								card.checkZeroCardStatement();
								card.checklimitPlusCard(pluscCardLimitperTurn);
								card.checkStatementPlusCard(pluscCardLimitperTurn);
								if (card.getPile().getNumber() == 10 || card.getPile().getNumber() == 11) {
									card.checkLostTurnCard(isLeftTurn);
								}
								
							}
						}
					}
					if (even.type == even.KeyPressed) {
						if (even.key.code == sf::Keyboard::A) {
							card.printPileColorAnsNUmber();
							card.showCardsToEat(isLeftTurn,atLeastOneCard);
						}
					//	if (even.key.code == sf::Keyboard::Z) {
					//		card.swapDecks();
					//	}
					}
					if (even.type == even.MouseButtonPressed) {
						for (int i = 0; i < 20; i++){ 
							{
							    if (card.playerDeckIsPressed(isLeftTurn,i,window, mouse, even)) {
								  card.printPileColorAnsNUmber(i, isLeftTurn);
								      if (card.isNotCardsToEat() || card.isCounterPlusCards(i, isLeftTurn)) {

									   card.checkValidCard(i, isLeftTurn, atLeastOneCard,CardsOfTheSameNumberPerTurn,pluscCardLimitperTurn);
 
								      }
								}
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