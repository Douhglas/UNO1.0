#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "Deck.h"
#include "Game.h"
#include "Menu.h"
#include "Card.h"

//change buttons texture

using namespace std;
int main() {

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1200, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;
	bool isMultiPlayer = false;
	bool isSinglePlayer = false;
	/*
	bool isEndGame = false;
	bool isLeftTurn = true;
	int CardsOfTheSameNumberPerTurn = 0;
	int pluscCardLimitperTurn = 0;
	int plusCardStatement = 0;
	int color;
	int numCard;
	bool startGame = false;
	int atLeastOneCard = 0;
	bool isUnobuttonPressed = false;
	*/
	bool isRunningGame = true;

	while (isRunningGame) {
		bool isEndGame = false;
		bool isLeftTurn = true;
		int CardsOfTheSameNumberPerTurn = 0;
		int pluscCardLimitperTurn = 0;
		int plusCardStatement = 0;
		int color;
		int numCard;
		bool startGame = false;
		int atLeastOneCard = 0;
		bool isUnobuttonPressed = false;
		bool isRunningGame = true;

		Card card(&window);
		isEndGame = false;

		window.create(sf::VideoMode(1200, 900), "MENU");
		while (window.isOpen()) {

			sf::Event eve;

			while (window.pollEvent(eve)) {


				if (eve.type == eve.Closed) {

					window.close();
					isRunningGame = false;

				}
				if (eve.type == eve.MouseButtonPressed && card.isButtonPressed(0, window, mouse, eve)) {

					window.close();
					isSinglePlayer = true;
					

				}
				if (eve.type == eve.MouseButtonPressed && card.isButtonPressed(1, window, mouse, eve)) {

					window.close();
					isMultiPlayer = true;
				}

			}

			window.clear();
			card.drawOptions(&window);
			window.display();
		}

		if (isMultiPlayer == true) {

			window.create(sf::VideoMode(1200, 900), "MultiPlayer");
			while (window.isOpen())
			{
				card.checkStatementColorChange();
				sf::Event even;

				color = rand() % 4;
				numCard = rand() % 15;



				while (window.pollEvent(even)) {

					if (even.type == even.Closed) {

						window.close();
						isMultiPlayer = false;

					}
					if (even.type == even.MouseButtonPressed && card.isButtonPressed(2, window, mouse, even)) {
						card.initPileCard(color, numCard);
						card.init8CardsPerDeck();
						startGame = true;
						card.RemoveButton(2);
					}
					if (even.type == even.MouseButtonPressed && card.isButtonPressed(3, window, mouse, even)) {
						if (isLeftTurn == true && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {

						}
						if (isLeftTurn == false && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {

						}
					}
					if (!isEndGame) {
						if (even.type == even.MouseButtonPressed) {
							if (card.mainDeckIsPressed(window, mouse, even)) {
								card.getTypeCard(color, numCard, isLeftTurn);
							}
						}
					}
					if (even.type == even.KeyPressed) {
						if (even.key.code == sf::Keyboard::Enter) {
							if ((isLeftTurn == true && atLeastOneCard != 0) && card.isNotCardsToEat() == true ||
								((isLeftTurn == true && atLeastOneCard != 0) && (card.getPile().getNumber() == 12 || card.getPile().getNumber() == 16))) {

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
							if ((isLeftTurn == false && atLeastOneCard != 0) && card.isNotCardsToEat() == true ||
								((isLeftTurn == false && atLeastOneCard != 0) && (card.getPile().getNumber() == 12 || card.getPile().getNumber() == 16))) {

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
							card.showCardsToEat(isLeftTurn, atLeastOneCard);
						}
						if (even.key.code == sf::Keyboard::Q) {
							cout << " q" << endl;
							if (isUnobuttonPressed == true) {
								cout << "true" << endl;
							}
							else {
								cout << "false" << endl;
							}
							if (isLeftTurn == true && card.AmountOfCardsInPLayerDeck(true) == 1) {
								isUnobuttonPressed = true;
							}
							if (isUnobuttonPressed == false && card.AmountOfCardsInPLayerDeck(false) == 1) {
								card.unoButtonPenalty(false);

							}
						}
						if (even.key.code == sf::Keyboard::P) {
							cout << " p" << endl;
							if (isUnobuttonPressed == true) {
								cout << "true" << endl;
							}
							else {
								cout << "false" << endl;
							}

							if (isLeftTurn == false && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {
								isUnobuttonPressed = true;
							}
							if (isUnobuttonPressed == false && card.AmountOfCardsInPLayerDeck(true) == 1) {
								card.unoButtonPenalty(true);

							}
						}
					}
					if (!isEndGame) {
						if (even.type == even.MouseButtonPressed) {
							for (int i = 0; i < 24; i++) {
								{
									if (card.playerDeckIsPressed(isLeftTurn, i, window, mouse, even)) {
										card.printPileColorAnsNUmber(i, isLeftTurn);
										if (card.isNotCardsToEat() || card.isCounterPlusCards(i, isLeftTurn)) {

											card.checkValidCard(i, isLeftTurn, atLeastOneCard, CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn);

										}
									}
								}
							}
						}
					}


				}
				if (card.AmountOfCardsInPLayerDeck(true) > 1 && card.AmountOfCardsInPLayerDeck(false) > 1) {
					isUnobuttonPressed = false;
				}
				if ((card.AmountOfCardsInPLayerDeck(true) < 1 || card.AmountOfCardsInPLayerDeck(false) < 1) && startGame == true) {
					isEndGame = true;
				}

				window.clear();

				if (startGame) {
					card.drawDecks(&window);
					card.drawOptions(3, &window, isEndGame, isLeftTurn);
				}
				else {
					card.drawOptions(2, &window, isEndGame, isLeftTurn);


				}

				window.display();
			}
			
		}

		if (isSinglePlayer == true) {

			window.create(sf::VideoMode(1200, 900), "SinglePlayer");
			while (window.isOpen())
			{
				card.checkStatementColorChange();
				sf::Event even;

				color = rand() % 4;
				numCard = rand() % 15;



				while (window.pollEvent(even)) {

					if (even.type == even.Closed) {

						window.close();
						isSinglePlayer = false;

					}
					if (even.type == even.MouseButtonPressed && card.isButtonPressed(2, window, mouse, even)) {
						card.initPileCard(color, numCard);
						card.init8CardsPerDeck();
						startGame = true;
						card.RemoveButton(2);
					}
					if (even.type == even.MouseButtonPressed && card.isButtonPressed(3, window, mouse, even)) {
						if (isLeftTurn == true && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {

						}
						if (isLeftTurn == false && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {

						}
					}
					if (!isEndGame) {
						if (even.type == even.MouseButtonPressed) {
							if (card.mainDeckIsPressed(window, mouse, even)) {
								card.getTypeCard(color, numCard, isLeftTurn);
							}
						}
					}
					if (even.type == even.KeyPressed) {
						if (even.key.code == sf::Keyboard::Enter) {
							if ((isLeftTurn == true && atLeastOneCard != 0) && card.isNotCardsToEat() == true ||
								((isLeftTurn == true && atLeastOneCard != 0) && (card.getPile().getNumber() == 12 || card.getPile().getNumber() == 16))) {

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
							if ((isLeftTurn == false && atLeastOneCard != 0) && card.isNotCardsToEat() == true ||
								((isLeftTurn == false && atLeastOneCard != 0) && (card.getPile().getNumber() == 12 || card.getPile().getNumber() == 16))) {

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
							card.showCardsToEat(isLeftTurn, atLeastOneCard);
						}
						if (even.key.code == sf::Keyboard::Q) {
							cout << " q" << endl;
							if (isUnobuttonPressed == true) {
								cout << "true" << endl;
							}
							else {
								cout << "false" << endl;
							}
							if (isLeftTurn == true && card.AmountOfCardsInPLayerDeck(true) == 1) {
								isUnobuttonPressed = true;
							}
							if (isUnobuttonPressed == false && card.AmountOfCardsInPLayerDeck(false) == 1) {
								card.unoButtonPenalty(false);

							}
						}
						if (even.key.code == sf::Keyboard::P) {
							cout << " p" << endl;
							if (isUnobuttonPressed == true) {
								cout << "true" << endl;
							}
							else {
								cout << "false" << endl;
							}

							if (isLeftTurn == false && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {
								isUnobuttonPressed = true;
							}
							if (isUnobuttonPressed == false && card.AmountOfCardsInPLayerDeck(true) == 1) {
								card.unoButtonPenalty(true);

							}
						}
					}
					if (!isEndGame) {
						if (even.type == even.MouseButtonPressed) {
							for (int i = 0; i < 24; i++) {
								{
									if (card.playerDeckIsPressed(isLeftTurn, i, window, mouse, even)) {
										card.printPileColorAnsNUmber(i, isLeftTurn);
										if (card.isNotCardsToEat() || card.isCounterPlusCards(i, isLeftTurn)) {

											card.checkValidCard(i, isLeftTurn, atLeastOneCard, CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn);

										}
									}
								}
							}
						}
					}


				}
				if (card.AmountOfCardsInPLayerDeck(true) > 1 && card.AmountOfCardsInPLayerDeck(false) > 1) {
					isUnobuttonPressed = false;
				}
				if ((card.AmountOfCardsInPLayerDeck(true) < 1 || card.AmountOfCardsInPLayerDeck(false) < 1) && startGame == true) {
					isEndGame = true;
				}

				window.clear();

				if (startGame) {
					card.drawDecks(&window);
					card.drawOptions(3, &window, isEndGame, isLeftTurn);
				}
				else {
					card.drawOptions(2, &window, isEndGame, isLeftTurn);


				}

				window.display();
			}
		
		}
    
	}
}