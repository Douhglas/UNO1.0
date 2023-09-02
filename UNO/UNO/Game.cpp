#include "Game.h"

bool Game::isButtonPressed(sf::Shape& button, sf::RenderWindow& window, sf::Mouse& mouse, sf::Event& eve)
{
	if (isMouseOver(button, window, mouse) && eve.key.code == sf::Mouse::Left) {
		return true;
	}
	return false;

}

bool Game::isMouseOver(sf::Shape& button, sf::RenderWindow& window, sf::Mouse mouse)
{
	sf::Vector2f mousePosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
	if (button.getGlobalBounds().contains(mousePosition)) {
		return true;
	}
	return false;

}
