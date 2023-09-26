#include "Menu.h"

Menu::Menu(sf::RenderWindow& window)
{
	buttons[0].initButtons( sf::Vector2f(250, 150), sf::Vector2f(window.getSize().x / 2 - 125, window.getSize().y / 4),
		getOptionTexture1());
	buttons[1].initButtons( sf::Vector2f(250, 150), sf::Vector2f(window.getSize().x / 2 - 125, window.getSize().y / 2),
		getOptionTexture2());
	buttons[2].initButtons( sf::Vector2f(250, 150), sf::Vector2f(window.getSize().x / 2 - 125, window.getSize().y / 3),
		getOptionTexture3());
	buttons[3].initButtons( sf::Vector2f(200, 125), sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / 2),
		getOptionTexture4());
	winner[0].initButtons(sf::Vector2f(400, 350), sf::Vector2f(50, window.getSize().y / 2),
		getOptionTexture5());
	winner[1].initButtons(sf::Vector2f(400, 350), sf::Vector2f(750, window.getSize().y / 2),
		getOptionTexture5());

}

Menu::~Menu()
{
}

void Menu::drawOptions(sf::RenderWindow* window)
{
	window->draw(buttons[0].getButtonShape());

	window->draw(buttons[1].getButtonShape());
	
}

void Menu::drawOptions(int buttonNum, sf::RenderWindow* window, bool endGame, bool isLeftTurn)
{
	if (endGame == true) {
		if (isLeftTurn) {
			window->draw(winner[0].getButtonShape());
		}
		if (!isLeftTurn) {
			window->draw(winner[1].getButtonShape());
		}
	}
	else {
		window->draw(buttons[buttonNum].getButtonShape());
	}
}

bool Menu::isMouseOver(int button, sf::RenderWindow& window, sf::Mouse mouse)
{
	sf::Vector2f mousePosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
	if (buttons[button].getButtonShape().getGlobalBounds().contains(mousePosition)) {
		return true;
	}
	return false;
}

bool Menu::isMouseOver(sf::RectangleShape shape, sf::RenderWindow& window, sf::Mouse mouse)
{
	sf::Vector2f mousePosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
	if (shape.getGlobalBounds().contains(mousePosition)) {
		return true;
	}
	return false;
	
}

bool Menu::isButtonPressed(int button, sf::RenderWindow& window, sf::Mouse& mouse, sf::Event& eve)
{
	if (isMouseOver(button, window, mouse) && eve.key.code == sf::Mouse::Left) {
		return true;
	}
	return false;

}

bool Menu::isButtonPressed(sf::RectangleShape shape, sf::RenderWindow& window, sf::Mouse& mouse, sf::Event& eve)
{
	if (isMouseOver(shape, window, mouse) && eve.key.code == sf::Mouse::Left) {
		return true;
	}
	return false;
}

void Menu::RemoveButton(int button)
{
	buttons[button].initButtons( sf::Vector2f(10, 15), sf::Vector2f(0, 0), getOptionTexture1());
}






