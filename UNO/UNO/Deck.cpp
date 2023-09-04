#include "Deck.h"

Deck::Deck(sf::RenderWindow* window)
{
	if (!playersDeckTexture.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\UNO.png")) {

	}

	if (!MainDeckTexture.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\UNOBACK.jpg")) {

	}

	initMainDeck(window);

	initPile(window);

	initSizeOfDecksTexture();

	initPlayerDeckLeft();

	initPlayerDeckRight();

	initPlayersDecksTexture();

}

Deck::~Deck()
{
}

void Deck::initMainDeck(sf::RenderWindow* window)
{
	mainDeck.setSize(sf::Vector2f(sf::Vector2f(150,200)));

	mainDeck.setPosition(window->getSize().x / 3 + 25, window->getSize().y / 6);

	mainDeck.setTexture(&MainDeckTexture);
}

void Deck::initPile(sf::RenderWindow* window)
{
	pile.initDeckShape(sf::Vector2f(window->getSize().x / 2 + 25, window->getSize().y / 6), sf::Vector2f(150, 200));
	pile.setTexture(&playersDeckTexture);
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

void Deck::initPlayersDecksTexture()
{
	for (int i = 0; i < 20; i++) {

		playerDeckLeft[i].setTexture(&playersDeckTexture);

		playerDeckRight[i].setTexture(&playersDeckTexture);

		playerDeckLeft[i].setTextureRect(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		playerDeckRight[i].setTextureRect(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

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

	window->draw(mainDeck);

	window->draw(pile.getDeckShape());

	for (int i = 0; i < 20; i++) {

		window->draw(playerDeckLeft[i].getDeckShape());

		window->draw(playerDeckRight[i].getDeckShape());

	}

}

void Deck::initSizeOfDecksTexture()
{
	sizeOfDecksTexture = playersDeckTexture.getSize();

	sizeOfDecksTexture.x /= 14;
	sizeOfDecksTexture.y /= 8;
}
