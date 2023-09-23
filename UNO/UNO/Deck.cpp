#include "Deck.h"

Deck::Deck(sf::RenderWindow* window): Menu(*window)
{

	for (int i = 0; i < 20; i++) {
		emptyposLeft[i] = 0;
		emptyposRight[i] = 0;
	}

	if (!playersDeckTexture.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\UNO.png")) {

	}

	if (!MainDeckTexture.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\UNOBACK.jpg")) {

	}

	initMainDeck(window);

	initPile(window);

	pile.setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
		sizeOfDecksTexture.x, sizeOfDecksTexture.y);

	pile.setColor(0);

	pile.setNumber(0);

	initSizeOfDecksTexture();

	initPlayerDeckLeft();

	initPlayerDeckRight();

	initPlayersDecksTexture();

}

Deck::~Deck()
{
}

sf::RectangleShape Deck::getMainDeck()
{
	return mainDeck;
}

DeckShape Deck::getPile()
{
	return pile;
}

sf::Vector2u Deck::getSizeOfDecksTexture()
{
	return sizeOfDecksTexture;
}

void Deck::initFirstPileCard(int color, int number)
{
	if (number == 14) {

		pile.setTextureRectt(sizeOfDecksTexture.x * 13, sizeOfDecksTexture.y * 5,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		pile.setColor(0);

		pile.setNumber(14);

	}
	else {
		pile.setTextureRectt(sizeOfDecksTexture.x * number, sizeOfDecksTexture.y * color,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		pile.setColor(color);

		pile.setNumber(number);
	}
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

			playerDeckLeft[aux].initDeckShape(sf::Vector2f(decksPos.x + (j * 75), decksPos.y), sf::Vector2f(70,90));
			aux++;

		}

		decksPos.y += 95;
	}
}

void Deck::initPlayersDecksTexture()
{
	for (int i = 0; i < 20; i++) {

		playerDeckLeft[i].setTexture(&playersDeckTexture);

		playerDeckRight[i].setTexture(&playersDeckTexture);

		playerDeckLeft[i].setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 5,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		playerDeckRight[i].setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 5,
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

			playerDeckRight[aux].initDeckShape(sf::Vector2f(decksPos.x + (j * 75), decksPos.y),sf::Vector2f(70,90));

			aux++;
		}
		decksPos.y += 95;
	}
}

void Deck::initSizeOfDecksTexture()
{
	sizeOfDecksTexture = playersDeckTexture.getSize();

	sizeOfDecksTexture.x /= 14;
	sizeOfDecksTexture.y /= 8;

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

int Deck::checkEmptyPos(bool isleftTurn)
{
	if (isleftTurn == true) {
		for (int i = 0; i < 20; i++) {
			if (emptyposLeft[i] == 0) {

				emptyposLeft[i] = 1;
				return i;
				break;
			}
		}
	}
	if (isleftTurn == false) {
		for (int i = 0; i < 20; i++) {
			if (emptyposRight[i] == 0) {

				emptyposRight[i] = 1;
				return i;
				break;
			}
		}
	}
	
}

void Deck::setDeckPLayerTextureRect(int color, int numcard, bool isLeftTurn)
{
	int pos = checkEmptyPos(isLeftTurn);
	if (isLeftTurn == true) {
		playerDeckLeft[pos].setTextureRectt(sizeOfDecksTexture.x * numcard, sizeOfDecksTexture.y * color,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		playerDeckLeft[pos].setColor(color);

		playerDeckLeft[pos].setNumber(numcard);

		if (color == 5 && numcard == 13) {
			playerDeckLeft[pos].setColor(6);

			playerDeckLeft[pos].setNumber(14);
		}
		
	}
	if (isLeftTurn == false) {
		playerDeckRight[pos].setTextureRectt(sizeOfDecksTexture.x * numcard, sizeOfDecksTexture.y * color,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		
		playerDeckRight[pos].setColor(color);

		playerDeckRight[pos].setNumber(numcard);

		if (color == 5 && numcard == 13) {
			playerDeckRight[pos].setColor(6);

			playerDeckRight[pos].setNumber(14);
		}
	
	}
}

bool Deck::mainDeckIsPressed(sf::RenderWindow& window , sf::Mouse mouse ,sf::Event eve)
{
	return isButtonPressed(mainDeck,window,mouse,eve);
}

bool Deck::playerDeckIsPressed(bool isLeftTurn, int pos, sf::RenderWindow& window, sf::Mouse mouse, sf::Event eve)
{
	if (isLeftTurn == true) {

		return isButtonPressed(playerDeckLeft[pos].getDeckShape(), window, mouse, eve);

	}
	if (isLeftTurn == false) {

		return isButtonPressed(playerDeckRight[pos].getDeckShape(), window, mouse, eve);

	}
}

void Deck::setCardInPile(int card , bool isLeftTurn)
{
	
	if (isLeftTurn == true) {
		if (playerDeckLeft[card].getNumber() == 14) {

			pile.setTextureRectt(sizeOfDecksTexture.x * 13, sizeOfDecksTexture.y * 5,
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		}
		else {
			pile.setTextureRectt(sizeOfDecksTexture.x * playerDeckLeft[card].getNumber(), sizeOfDecksTexture.y * playerDeckLeft[card].getColor(),
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		}
			pile.setColor(playerDeckLeft[card].getColor());

			pile.setNumber(playerDeckLeft[card].getNumber());

			removeCardFromPLayerDeck(card, isLeftTurn);

			emptyposLeft[card] = 0;
		
	}
	if (isLeftTurn == false) {
		if (playerDeckRight[card].getNumber() == 14) {

			pile.setTextureRectt(sizeOfDecksTexture.x * 13, sizeOfDecksTexture.y * 5,
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		}
		else {
			pile.setTextureRectt(sizeOfDecksTexture.x * playerDeckRight[card].getNumber(), sizeOfDecksTexture.y * playerDeckRight[card].getColor(),
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		}
			pile.setColor(playerDeckRight[card].getColor());

			pile.setNumber(playerDeckRight[card].getNumber());

			removeCardFromPLayerDeck(card, isLeftTurn);

			emptyposRight[card] = 0;

	}
}

void Deck::removeCardFromPLayerDeck(int card, bool isLeftTurn)
{
	if (isLeftTurn == true) {

		playerDeckLeft[card].setColor(101);
		playerDeckLeft[card].setNumber(101);
		playerDeckLeft[card].setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

	}
	if (isLeftTurn == false) {

		playerDeckRight[card].setColor(101);
		playerDeckRight[card].setNumber(101);
		playerDeckRight[card].setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

	}
}

void Deck::checkValidCard(int card, bool isLeftTurn, int& atleastOneCard, int& CardsOfTheSameNumberPerTur, int& PlusCardLimitPerTurn)
{

	if (isLeftTurn == true) {
		if (playerDeckLeft[card].getNumber()>0 &&playerDeckLeft[card].getNumber()<10) {
               
			setNormalCardInPile(card,isLeftTurn,atleastOneCard,CardsOfTheSameNumberPerTur);

		}
		else {

			setSpecialCardInPile(card, isLeftTurn, atleastOneCard, CardsOfTheSameNumberPerTur,PlusCardLimitPerTurn);
		}
	}
	if (isLeftTurn == false) {
		if (playerDeckRight[card].getNumber() > 0 && playerDeckRight[card].getNumber() < 10) {

			setNormalCardInPile(card, isLeftTurn, atleastOneCard, CardsOfTheSameNumberPerTur);

		}
		else {
			setSpecialCardInPile(card, isLeftTurn, atleastOneCard, CardsOfTheSameNumberPerTur,PlusCardLimitPerTurn);
		}
	}
}

void Deck::printPileColorAnsNUmber()
{
	cout << pile.getColor() << "    " << pile.getNumber() << endl;


}

void Deck::printPileColorAnsNUmber(int i, bool isLeftTurn)
{
	if (isLeftTurn == true) {
		cout << playerDeckLeft[i].getColor() << "<<<<<" << playerDeckLeft[i].getNumber() << endl;

	}
	if (isLeftTurn == false) {
		cout << playerDeckRight[i].getColor() << "<<<<<" << playerDeckRight[i].getNumber() << endl;
	}
}

void Deck::checkStatementColorChange()
{
	
	if (pile.getNumber() == 13) {

		int newColor = 0;
		cout << "New color" << endl;
		cout << "0 == red" << endl;
		cout << "1 == yellow" << endl;
		cout << "2 == green" << endl;
		cout << "3 == blue" << endl;

		cin >> newColor;

		pile.setColor(newColor);
		pile.setNumber(15);

	}
	if (pile.getNumber() == 14) {
		
		int newColor = 0;
		cout << "New color" << endl;
		cout << "0 == red" << endl;
		cout << "1 == yellow" << endl;
		cout << "2 == green" << endl;
		cout << "3 == blue" << endl;

		cin >> newColor;

		pile.setColor(newColor);
		pile.setNumber(16);

	}

}

bool Deck::isCounterPlusCards(int pos, bool isLeftTurn)
{
	if (isLeftTurn == true) {
		if (playerDeckLeft[pos].getNumber() == 12 || playerDeckLeft[pos].getNumber() == 14) {
			return true;
		}
	}
	if (isLeftTurn == false) {
		if (playerDeckRight[pos].getNumber() == 12 || playerDeckRight[pos].getNumber() == 14) {
			return true;
		}
	}
	return false;
}

void Deck::setSpecialCardInPile(int card, bool isLeftTurn, int& atleastOneCard, int& CardsOfTheSameNumberPerTurn, int& PlusCardLimitPerTurn)
{ 
	if (isLeftTurn == true) {
		if (playerDeckLeft[card].getNumber() == 0 && ((playerDeckLeft[card].getColor() == pile.getColor() ||
			playerDeckLeft[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if (playerDeckLeft[card].getNumber() == 10 && ((playerDeckLeft[card].getColor() == pile.getColor() ||
			playerDeckLeft[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if (playerDeckLeft[card].getNumber() == 11 && ((playerDeckLeft[card].getColor() == pile.getColor() ||
			playerDeckLeft[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)){

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
	    }
		if ((playerDeckLeft[card].getNumber() == 12 && PlusCardLimitPerTurn ==0) && ((playerDeckLeft[card].getColor() == pile.getColor() ||
			playerDeckLeft[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;

		}
		if (playerDeckLeft[card].getNumber() == 13) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if (playerDeckLeft[card].getNumber() == 14) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}


	}
	if (isLeftTurn == false) {

		if (playerDeckRight[card].getNumber() == 0 && ((playerDeckRight[card].getColor() == pile.getColor() ||
			playerDeckRight[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if (playerDeckRight[card].getNumber() == 10 && ((playerDeckRight[card].getColor() == pile.getColor() ||
			playerDeckRight[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if (playerDeckRight[card].getNumber() == 11 && ((playerDeckRight[card].getColor() == pile.getColor() ||
			playerDeckRight[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if ((playerDeckRight[card].getNumber() == 12 && PlusCardLimitPerTurn == 0 )&&((playerDeckRight[card].getColor() == pile.getColor() ||
			playerDeckRight[card].getNumber() == pile.getNumber()) || pile.getNumber() == 11)) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;

		}
		if (playerDeckRight[card].getNumber() == 13) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}
		if (playerDeckRight[card].getNumber() == 14) {

			setCardInPile(card, isLeftTurn);
			atleastOneCard++;
		}

	}
}

void Deck::setNormalCardInPile(int card, bool isLeftTurn, int& atleastOneCard, int& CardsOfTheSameNumberPerTurn)
{
	if (isLeftTurn == true) {
		if (((pile.getColor() == playerDeckLeft[card].getColor() || (pile.getNumber() == playerDeckLeft[card].getNumber() &&
			CardsOfTheSameNumberPerTurn == 0)) || pile.getNumber() == 11) && playerDeckLeft[card].getColor() != 4){

			if (pile.getNumber() == playerDeckLeft[card].getNumber()&& pile.getColor() != playerDeckLeft[card].getColor()) {
				CardsOfTheSameNumberPerTurn++;
			}

			setCardInPile(card, isLeftTurn);

			atleastOneCard++;
		}
	}
	if (isLeftTurn == false) {
		if (((pile.getColor() == playerDeckRight[card].getColor() || (pile.getNumber() == playerDeckRight[card].getNumber() &&
			CardsOfTheSameNumberPerTurn == 0)) || pile.getNumber() == 11) && playerDeckRight[card].getColor() != 4) {

			if (pile.getNumber() == playerDeckRight[card].getNumber() && pile.getColor() != playerDeckRight[card].getColor()) {
				CardsOfTheSameNumberPerTurn++;
			}

			setCardInPile(card, isLeftTurn);

			atleastOneCard++;
		}
	}
}

void Deck::swapDecks()
{
	DeckShape auxShape;
	for (int i = 0; i < 20; i++) {

		int PosAux[20];
		PosAux[i] = emptyposLeft[i];
		emptyposLeft[i] = emptyposRight[i];
		emptyposRight[i] = PosAux[i];

		int auxColor = playerDeckLeft[i].getColor();
		int auxNumber = playerDeckLeft[i].getNumber();

		playerDeckLeft[i].setTextureRectt(sizeOfDecksTexture.x * playerDeckRight[i].getNumber(), sizeOfDecksTexture.y * playerDeckRight[i].getColor(),
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		playerDeckLeft[i].setColor(playerDeckRight[i].getColor());

		playerDeckLeft[i].setNumber(playerDeckRight[i].getNumber());

		if (playerDeckRight[i].getColor() == 6 && playerDeckRight[i].getNumber() == 14) {
			
			playerDeckLeft[i].setTextureRectt(sizeOfDecksTexture.x * 13, sizeOfDecksTexture.y * 5,
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		}


		playerDeckRight[i].setTextureRectt(sizeOfDecksTexture.x * auxNumber, sizeOfDecksTexture.y * auxColor,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		playerDeckRight[i].setColor(auxColor);

		playerDeckRight[i].setNumber(auxNumber);

		if (auxColor == 6 && auxNumber == 14) {
			
			playerDeckRight[i].setTextureRectt(sizeOfDecksTexture.x * 13, sizeOfDecksTexture.y * 5,
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);
		}


	}
}

void Deck::checkZeroCardStatement()
{
	if (pile.getNumber() == 0) {
		swapDecks();
	}
}









