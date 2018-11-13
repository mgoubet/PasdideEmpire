#include "PlayingScreen.h"
#include "PlayerGUI.h"
#include "GameGUI.h"
#include "BackgroundGUI.h"
#include <iostream>

PlayingScreen::PlayingScreen()
{
	PlayerGUI *l_player = new PlayerGUI();
	l_player->setPosition(GameGUI::SCREEN_WIDTH / 2, GameGUI::SCREEN_HEIGHT / 2);
	
	BackgroundGUI *l_backgroundGrass = new BackgroundGUI("Ressource/backgroundDarkGrass.png");
	l_backgroundGrass->setPosition(GameGUI::SCREEN_WIDTH / 2, GameGUI::SCREEN_HEIGHT / 2);

	BackgroundGUI *l_tree = new BackgroundGUI("Ressource/pine-tree.png");
	l_tree->setPosition(150, 150);

	m_gameObjectManager.add("Player", l_player);
	m_gameObjectManager.add("Background", l_backgroundGrass);
	m_gameObjectManager.add("Tree", l_tree);

}


PlayingScreen::~PlayingScreen()
{
}

PlayingScreen::PlayingResult PlayingScreen::show(sf::RenderWindow& a_window)
{
	while (true) {
		sf::Event l_currentEvent = GameGUI::getInput();
		a_window.clear(sf::Color(0, 0, 0));

		m_gameObjectManager.updateAll();
		m_gameObjectManager.drawAll(a_window);

		a_window.display();


		if (l_currentEvent.type == sf::Event::Closed) {
			return Exit;
		}

		if (l_currentEvent.type == sf::Event::KeyPressed)
		{
			if (l_currentEvent.key.code == sf::Keyboard::Escape) {
				return ReturnMenu;
			}
		}
	}
}

const GameObjectManager & PlayingScreen::getGameObjectManager()
{
	return PlayingScreen::m_gameObjectManager;
}

GameObjectManager PlayingScreen::m_gameObjectManager;