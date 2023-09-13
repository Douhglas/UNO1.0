#include "Deck.h"

Deck::Deck(sf::RenderWindow* window): Menu(*window)
{
	emptyPosLeftAux = 0;
	emptyPosRightaux = 0;

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

			playerDeckRight[aux].initDeckShape(sf::Vector2f(decksPos.x + (j * 85), decksPos.y),sf::Vector2f(80,100));

			aux++;
		}
		decksPos.y += 105;
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

		
	}
	if (isLeftTurn == false) {
		playerDeckRight[pos].setTextureRectt(sizeOfDecksTexture.x * numcard, sizeOfDecksTexture.y * color,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

		playerDeckRight[pos].setColor(color);

		playerDeckRight[pos].setNumber(numcard);

	
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
			pile.setTextureRectt(sizeOfDecksTexture.x * playerDeckLeft[card].getNumber(), sizeOfDecksTexture.y * playerDeckLeft[card].getColor(),
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);

			pile.setColor(playerDeckLeft[card].getColor());

			pile.setNumber(playerDeckLeft[card].getNumber());

			removeCardFromPLayerDeck(card, isLeftTurn);

			emptyposLeft[card] = 0;
	}
	if (isLeftTurn == false) {

			pile.setTextureRectt(sizeOfDecksTexture.x * playerDeckRight[card].getNumber(), sizeOfDecksTexture.y * playerDeckRight[card].getColor(),
				sizeOfDecksTexture.x, sizeOfDecksTexture.y);

			pile.setColor(playerDeckRight[card].getColor());

			pile.setNumber(playerDeckRight[card].getNumber());

			removeCardFromPLayerDeck(card, isLeftTurn);

			emptyposRight[card] = 0;

	}
}

void Deck::removeCardFromPLayerDeck(int card, bool isLeftTurn)
{
	if (isLeftTurn == true) {

		playerDeckLeft[card].setColor(4);
		playerDeckLeft[card].setNumber(0);
		playerDeckLeft[card].setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

	}
	if (isLeftTurn == false) {

		playerDeckRight[card].setColor(4);
		playerDeckRight[card].setNumber(0);
		playerDeckRight[card].setTextureRectt(sizeOfDecksTexture.x * 0, sizeOfDecksTexture.y * 4,
			sizeOfDecksTexture.x, sizeOfDecksTexture.y);

	}
}

void Deck::checkValidCard(int card, bool isLeftTurn, int& atleastOneCard)
{
	if (isLeftTurn == true) {
		if (((pile.getColor() == playerDeckLeft[card].getColor() || pile.getNumber() == playerDeckLeft[card].getNumber()) &&
			playerDeckLeft[card].getColor() != 5) || (playerDeckLeft[card].getNumber() == 13 || playerDeckLeft[card].getNumber() == 14)) {
               
			setCardInPile(card,isLeftTurn);

			atleastOneCard++;

		}
	}
	if (isLeftTurn == false) {
		if (((playerDeckRight[card].getColor() == pile.getColor() || playerDeckRight[card].getNumber() == pile.getNumber()) &&
			playerDeckRight[card].getColor() != 5) || (playerDeckRight[card].getNumber() == 13 || playerDeckRight[card].getNumber() == 14)) {

			setCardInPile(card, isLeftTurn);

			atleastOneCard++;
		}
	}
}

void Deck::printPileColorAnsNUmber()
{
	cout << pile.getColor() << "    " << pile.getNumber() << endl;
}




