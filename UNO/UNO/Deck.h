#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "DeckShape.h"
#include "Menu.h"
using namespace std;
class Deck: public Menu
{
private:

	int emptyposLeft[20];

	int emptyPosLeftAux;

	int emptyposRight[20];

	int emptyPosRightaux;

	sf::Texture MainDeckTexture;

	sf::Texture playersDeckTexture;

	sf::RectangleShape mainDeck;

    DeckShape pile;

	DeckShape playerDeckLeft[20];

	DeckShape playerDeckRight[20];

	sf::Vector2u sizeOfDecksTexture;

	void initMainDeck(sf::RenderWindow* window);

	void initPile(sf::RenderWindow* window);

	void initPlayerDeckLeft();

	void initPlayersDecksTexture();

	void initPlayerDeckRight();

	void initPlayerDeckRightTexture();

	void initSizeOfDecksTexture();



public:

	Deck(sf::RenderWindow* window);

	~Deck();

	sf::RectangleShape getMainDeck();

	DeckShape getPlayerDeckLeft(int pos);

	DeckShape getPlayerDeckRight(int pos);

	sf::Vector2u getSizeOfDecksTexture();

	void initFirstPileCard(int color ,int number);

	void drawDecks(sf::RenderWindow* window);

	int checkEmptyPos(bool isleftTurn);

	void setDeckPLayerTextureRect(int color,int numcard, bool isLeftTurn);
	
	bool mainDeckIsPressed(sf::RenderWindow& window, sf::Mouse mouse, sf::Event eve);

	bool playerDeckIsPressed(bool isLeftTurn, int pos, sf::RenderWindow& window, sf::Mouse mouse, sf::Event eve);

	void setCardInPile(int card , bool isLeftTurn);

	void removeCardFromPLayerDeck(int card, bool isLeftTurn);

	void initDeckPlayersCards();

	void checkValidCard(int card, bool isLeftTurn , int& atleastOneCard);

	void printPileColorAnsNUmber();
};

