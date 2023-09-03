#include "Deck.h"

Deck::Deck(sf::RenderWindow* window)
{
	initMainDeck(window);
	initPile(window);
	initPlayerDeckLeft();
	initPlayerDeckRight();
}

Deck::~Deck()
{
}

void Deck::initMainDeck(sf::RenderWindow* window)
{
	mainDeck.initDeckShape(sf::Vector2f(window->getSize().x / 3 + 25, window->getSize().y / 6),sf::Vector2f(150,200));

}

void Deck::initPile(sf::RenderWindow* window)
{
	pile.initDeckShape(sf::Vector2f(window->getSize().x / 2 + 25, window->getSize().y / 6), sf::Vector2f(150, 200));
}

void Deck::initPlayerDeckLeft()
{
	sf::Vector2f decksPos;

	decksPos.y = 425;
	int aux = 0;

	for (int i = 0; i < 4; i++) {

		decksPos.x = 30;
		
		for (int j = 0; j < 5; j++) {

			playerDeckLeft[aux].initDeckShape(sf::Vector2f(decksPos.x + (j * 85), decksPos.y), sf::Vector2f(80, 100));

			aux++;

		}

		decksPos.y += 105;
	}
}

void Deck::initPlayerDeckRight()
{
	sf::Vector2f decksPos;

	decksPos.y = 425;
	int aux = 0;

	for (int i = 0; i < 4; i++) {

		decksPos.x = 745;

		for (int j = 0; j < 5; j++) {

			playerDeckRight[aux].initDeckShape(sf::Vector2f(decksPos.x + (j * 85), decksPos.y),sf::Vector2f(80,100));

			aux++;
		}
		decksPos.y += 105;
	}
}

void Deck::drawDecks(sf::RenderWindow* window)
{

	window->draw(mainDeck.getDeckShape());

	window->draw(pile.getDeckShape());

	for (int i = 0; i < 20; i++) {

		window->draw(playerDeckLeft[i].getDeckShape());

		window->draw(playerDeckRight[i].getDeckShape());

	}

}
