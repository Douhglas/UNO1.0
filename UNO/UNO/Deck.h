#pragma once
#include <SFML/Graphics.hpp>
#include "DeckShape.h"
class Deck
{
private:
	
	DeckShape mainDeck;

    DeckShape pile;

	DeckShape playerDeckLeft[20];

	DeckShape playerDeckRight[20];

public:

	Deck(sf::RenderWindow* window);

	~Deck();

	void initMainDeck(sf::RenderWindow* window);

	void initPile(sf::RenderWindow* window);

	void initPlayerDeckLeft();

	void initPlayerDeckRight();

	void drawDecks(sf::RenderWindow* window);



};

