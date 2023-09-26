#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "DeckShape.h"
#include "Menu.h"
using namespace std;
class Deck: public Menu
{
private:
	
	static const int DECKSIZE= 24;

	int emptyposLeft[DECKSIZE];

	int emptyposRight[DECKSIZE];

	sf::Texture MainDeckTexture;

	sf::Texture playersDeckTexture;

	sf::RectangleShape mainDeck;

    DeckShape pile;

	DeckShape playerDeckLeft[DECKSIZE];

	DeckShape playerDeckRight[DECKSIZE];

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

	DeckShape getPile();

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

	void checkValidCard(int card, bool isLeftTurn , int& atleastOneCard, int& CardsOfTheSameNumberPerTurn, int& PlusCardLimitPerTurn);

	void printPileColorAnsNUmber();
	void printPileColorAnsNUmber(int i,bool isLeftTurn);

	void checkStatementColorChange();

	void checkStatementColorChange(int newColor);

	bool isCounterPlusCards(int pos, bool isLeftTurn);

	void setSpecialCardInPile(int card,bool isLeftTurn, int& atleastOneCard, int& CardsOfTheSameNumberPerTurn, int& PlusCardLimitPerTurn);

	void setNormalCardInPile(int card , bool isLeftTurn , int& atleastOneCard, int& CardsOfTheSameNumberPerTurn);

	void swapDecks();

	void checkZeroCardStatement();

	int AmountOfCardsInPLayerDeck(bool islefturn);

	void checkIfFirstCardInPileIsSpecial(int& atleastOneCard);


};

