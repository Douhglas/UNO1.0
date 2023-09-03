#include "Menu.h"

Menu::Menu(sf::RenderWindow& window)
{
	buttons[0].initButtons(sf::Vector2f(300, 200), sf::Vector2f(window.getSize().x / 2, window.getSize().y / 4),
		getOptionTexture1());

}

Menu::~Menu()
{
}

void Menu::drawOptions(sf::RenderWindow* window)
{
	window->draw(buttons[0].getButtonShape());
	
}

bool Menu::isMouseOver(int button, sf::RenderWindow& window, sf::Mouse mouse)
{
	sf::Vector2f mousePosition(mouse.getPosition(window).x, mouse.getPosition(window).y);
	if (buttons[button].getButtonShape().getGlobalBounds().contains(mousePosition)) {
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






