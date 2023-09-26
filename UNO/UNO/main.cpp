#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Card.h"
using namespace std;

void MenuWindow(sf::RenderWindow& window, Card& card, sf::Mouse& mouse, bool& isRunningGame, bool& isSinglePlayer, bool& isMultiPlayer);

void singlePlayerWindow(sf::RenderWindow& window, Card& card, sf::Mouse& mouse, bool& isRunningGame, bool& isSinglePlayer, bool& isLeftTurn,
	bool& startGame, bool& isEndGame, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn, int& pluscCardLimitperTurn, bool& isUnobuttonPressed);

void multiPlayerWindow(sf::RenderWindow& window, Card& card, sf::Mouse& mouse, bool& isRunningGame, bool& isMultiPlayer, bool& isLeftTurn,
	bool& startGame, bool& isEndGame, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn, int& pluscCardLimitperTurn, bool& isUnobuttonPressed);

void closeWindowSinglePlayer(sf::Event& even, sf::RenderWindow& window, bool& isSinglePlayer);

void closeWindowMultiPlayer(sf::Event& even, sf::RenderWindow& window, bool& isMultiPlayer);

void startGamee(sf::Event& even, sf::RenderWindow& window, Card& card, sf::Mouse& mouse, int& color, int& numCard, bool& startGame);

void getCard(sf::Event& even, sf::RenderWindow& window, Card& card, sf::Mouse& mouse, int& color, int& numCard, bool& isEndGame, bool& isLeftTurn);

void endTheTurnMultiPlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn,
	int& pluscCardLimitperTurn);

void endTheTurnSinglePlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn,
	int& pluscCardLimitperTurn);

void PressUnoButtonMultiPlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, bool& isUnobuttonPressed);

void PressUnoButtonSinglePlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, bool& isUnobuttonPressed);

void throwCardMultiPlayer(sf::Event& even, sf::RenderWindow& window, sf::Mouse& mouse, Card& card, bool& isLeftTurn, int& atLeastOneCard,
	int& pluscCardLimitperTurn, bool& isEndGame, int& CardsOfTheSameNumberPerTurn);

void throwCardSinglePlayer(sf::Event& even, sf::RenderWindow& window, sf::Mouse& mouse, Card& card, bool& isLeftTurn, int& atLeastOneCard,
	int& pluscCardLimitperTurn, bool& isEndGame, int& CardsOfTheSameNumberPerTurn);

void playComputerTurn(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn,
	int& pluscCardLimitperTurn, bool& isUnobuttonPressed, int& color, int& numCard);


int main() {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(1200, 900), "window", sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Mouse mouse;
	bool isMultiPlayer = false;
	bool isSinglePlayer = false;
	
	bool isRunningGame = true;

	while (isRunningGame) {
		bool isEndGame = false;
		bool isLeftTurn = true;
		int CardsOfTheSameNumberPerTurn = 0;
		int pluscCardLimitperTurn = 0;
		int plusCardStatement = 0;
		bool startGame = false;
		int atLeastOneCard = 0;
		bool isUnobuttonPressed = false;
		

		Card card(&window);
		isEndGame = false;

		MenuWindow(window, card, mouse, isRunningGame, isSinglePlayer, isMultiPlayer);

		singlePlayerWindow(window, card, mouse, isRunningGame, isSinglePlayer, isLeftTurn, startGame, isEndGame, atLeastOneCard,
			CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn, isUnobuttonPressed);

		multiPlayerWindow(window, card, mouse, isRunningGame, isMultiPlayer, isLeftTurn, startGame, isEndGame, atLeastOneCard,
			CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn, isUnobuttonPressed);
		
    
	}
}

void MenuWindow(sf::RenderWindow& window,Card& card,sf::Mouse& mouse,bool& isRunningGame, bool& isSinglePlayer, bool& isMultiPlayer)
{
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
}

void singlePlayerWindow(sf::RenderWindow& window, Card& card, sf::Mouse& mouse, bool& isRunningGame, bool& isSinglePlayer, bool& isLeftTurn,
	bool& startGame, bool& isEndGame, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn,int& pluscCardLimitperTurn, bool& isUnobuttonPressed)
{
	int color;
	int numCard;

	if (isSinglePlayer == true) {

		
		window.create(sf::VideoMode(1200, 900), "SinglePlayer");

		int color;
		int numCard;

		while (window.isOpen())
		{
			if (isLeftTurn) {
				card.checkStatementColorChange();
			}


			sf::Event even;

			color = rand() % 4;
			numCard = rand() % 15;



			while (window.pollEvent(even)) {

				closeWindowSinglePlayer(even,window,isSinglePlayer);

				startGamee(even,window,card,mouse,color,numCard,startGame);

				getCard(even, window, card, mouse, color, numCard, isEndGame, isLeftTurn);

				endTheTurnSinglePlayer(even, card, isLeftTurn, atLeastOneCard, CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn);

				PressUnoButtonSinglePlayer(even, card, isLeftTurn, atLeastOneCard, isUnobuttonPressed);

				throwCardSinglePlayer(even, window, mouse, card, isLeftTurn, atLeastOneCard, pluscCardLimitperTurn, isEndGame,
					CardsOfTheSameNumberPerTurn);


			}

			playComputerTurn(even, card, isLeftTurn, atLeastOneCard, CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn, isUnobuttonPressed,
				color, numCard);


			if (card.AmountOfCardsInPLayerDeck(true) > 1 && card.AmountOfCardsInPLayerDeck(false) > 1) {
				isUnobuttonPressed = false;
			}
			if ((card.AmountOfCardsInPLayerDeck(true) < 1 || card.AmountOfCardsInPLayerDeck(false) < 1) && startGame == true) {
				isEndGame = true;
			}



			window.clear();

			if (startGame) {
				card.drawDecks(&window);
				if (card.AmountOfCardsInPLayerDeck(false) == 0) {
					card.drawOptions(3, &window, isEndGame, false);
				}
				else {
					card.drawOptions(3, &window, isEndGame, isLeftTurn);
				}
			}
			else {
				card.drawOptions(2, &window, isEndGame, isLeftTurn);

			}

			window.display();
		}

	}
}

void multiPlayerWindow(sf::RenderWindow& window, Card& card, sf::Mouse& mouse, bool& isRunningGame, bool& isMultiPlayer, bool& isLeftTurn,
	bool& startGame, bool& isEndGame, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn, int& pluscCardLimitperTurn, bool& isUnobuttonPressed)
{

	if (isMultiPlayer == true) {

		window.create(sf::VideoMode(1200, 900), "MultiPlayer");
		int color;
		int numCard;

		while (window.isOpen())
		{
			card.checkStatementColorChange();
			sf::Event even;

			color = rand() % 4;
			numCard = rand() % 15;



			while (window.pollEvent(even)) {

				closeWindowMultiPlayer(even,window,isMultiPlayer);

				startGamee(even,window,card,mouse,color,numCard,startGame);

				getCard(even, window, card, mouse, color, numCard,isEndGame,isLeftTurn);

				endTheTurnMultiPlayer(even, card, isLeftTurn, atLeastOneCard, CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn);
				
				PressUnoButtonMultiPlayer(even,card,isLeftTurn,atLeastOneCard,isUnobuttonPressed);

				throwCardMultiPlayer(even,window,mouse,card,isLeftTurn,atLeastOneCard,pluscCardLimitperTurn,isEndGame,CardsOfTheSameNumberPerTurn);


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

void closeWindowSinglePlayer(sf::Event& even, sf::RenderWindow& window, bool& isSinglePlayer)
{
	if (even.type == even.Closed) {

		window.close();
		isSinglePlayer = false;

	}
}

void closeWindowMultiPlayer(sf::Event& even, sf::RenderWindow& window, bool& isMultiPlayer)
{
	if (even.type == even.Closed) {

		window.close();
		isMultiPlayer = false;

	}
}

void startGamee(sf::Event& even, sf::RenderWindow& window, Card& card, sf::Mouse& mouse, int& color, int& numCard,bool& startGame)
{
	if (even.type == even.MouseButtonPressed && card.isButtonPressed(2, window, mouse, even)) {
		card.initPileCard(color, numCard);
		card.init8CardsPerDeck();
		startGame = true;
		card.RemoveButton(2);
	}
}

void getCard(sf::Event& even, sf::RenderWindow& window, Card& card, sf::Mouse& mouse, int& color, int& numCard, bool& isEndGame, bool& isLeftTurn)
{
	if (!isEndGame) {
		if (even.type == even.MouseButtonPressed) {
			if (card.mainDeckIsPressed(window, mouse, even)) {
				card.getTypeCard(color, numCard, isLeftTurn);
			}
		}
	}
}

void endTheTurnMultiPlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn, 
	int& pluscCardLimitperTurn)
{
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
}

void endTheTurnSinglePlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn,
	int& pluscCardLimitperTurn)
{
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
		}
	}
}

void PressUnoButtonMultiPlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, bool& isUnobuttonPressed)
{
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
}

void PressUnoButtonSinglePlayer(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, bool& isUnobuttonPressed)
{
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

	}
}

void throwCardMultiPlayer(sf::Event& even, sf::RenderWindow& window, sf::Mouse& mouse, Card& card, bool& isLeftTurn, int& atLeastOneCard,
	int& pluscCardLimitperTurn, bool& isEndGame, int& CardsOfTheSameNumberPerTurn)
{
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

void throwCardSinglePlayer(sf::Event& even, sf::RenderWindow& window, sf::Mouse& mouse, Card& card, bool& isLeftTurn, int& atLeastOneCard,
	int& pluscCardLimitperTurn, bool& isEndGame, int& CardsOfTheSameNumberPerTurn)
{
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

void playComputerTurn(sf::Event& even, Card& card, bool& isLeftTurn, int& atLeastOneCard, int& CardsOfTheSameNumberPerTurn,
	int& pluscCardLimitperTurn, bool& isUnobuttonPressed, int& color ,int& numCard)
{
	if (!isLeftTurn) {
		if ((isUnobuttonPressed == false && card.AmountOfCardsInPLayerDeck(true) == 1) && !isLeftTurn) {
			card.unoButtonPenalty(true);

		}

		for (int i = 0; i < 24; i++) {



			if (card.isNotCardsToEat() || card.isCounterPlusCards(i, isLeftTurn)) {

				card.checkValidCard(i, isLeftTurn, atLeastOneCard, CardsOfTheSameNumberPerTurn, pluscCardLimitperTurn);

				card.checkStatementColorChange(rand() & 3);

				if (isLeftTurn == false && card.AmountOfCardsInPLayerDeck(isLeftTurn) == 1) {
					isUnobuttonPressed = true;
				}
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
		if (!isLeftTurn) {
			card.getTypeCard(color, numCard, isLeftTurn);

		}


	}
}
