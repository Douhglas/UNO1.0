#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:

public:

	bool isMouseOver(sf::Shape& button, sf::RenderWindow& window, sf::Mouse mouse);
	bool isButtonPressed(sf::Shape& button, sf::RenderWindow& window, sf::Mouse& mouse, sf::Event& eve);

};
