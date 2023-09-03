#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	initTextures();
}

Game::~Game()
{
}

sf::Texture Game::getOptionTexture1()
{
	return optionTexture1;
}

void Game::initTextures()
{
	if (!optionTexture1.loadFromFile("C:\\Users\\Usuario\\Desktop\\UNO_1.0\\UNO1.0\\UNO\\Textures\\Narizonk.jpg")) {
		cout << " ERROR optionTexture1" << endl;
	}
}

