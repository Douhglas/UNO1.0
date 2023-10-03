#pragma once
#include "Game.h"
#include "MenuShape.h"
class Menu : public Game
{
private:

	MenuShape buttons[4];//Numeros mágicos
	MenuShape winner[2];

//Evitar estos espacios en blanco 

public:

	Menu(sf::RenderWindow& window);

	~Menu();

	void drawOptions( sf::RenderWindow* window);

	void drawOptions( int buttonNum ,sf::RenderWindow* window, bool endGame, bool isLeftTurn);

	bool isMouseOver(int button, sf::RenderWindow& window, sf::Mouse mouse);

	bool isMouseOver(sf::RectangleShape shape, sf::RenderWindow& window, sf::Mouse mouse);

	bool isButtonPressed(int button, sf::RenderWindow& window, sf::Mouse& mouse, sf::Event& eve);

	bool isButtonPressed(sf::RectangleShape shape, sf::RenderWindow& window, sf::Mouse& mouse, sf::Event& eve);

	void RemoveButton(int button);

	
};

