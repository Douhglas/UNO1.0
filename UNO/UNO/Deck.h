#pragma once
#include <SFML/Graphics.hpp>
#include "DeckShape.h"
using namespace std;
class Deck
{
private:

	sf::Texture MainDeckTexture;

	sf::Texture playersDeckTexture;

	sf::RectangleShape mainDeck;

    DeckShape pile;

	DeckShape playerDeckLeft[20];

	DeckShape playerDeckRight[20];

	sf::Vector2u sizeOfDecksTexture;

public:

	Deck(sf::RenderWindow* window);

	~Deck();

	void initMainDeck(sf::RenderWindow* window);

	void initPile(sf::RenderWindow* window);

	void initPlayerDeckLeft();

	void initPlayersDecksTexture();

	void initPlayerDeckRight();

	void initPlayerDeckRightTexture();

	void drawDecks(sf::RenderWindow* window);

	void initSizeOfDecksTexture();
	
};

