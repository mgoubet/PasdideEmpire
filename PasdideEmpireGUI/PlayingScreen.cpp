#include "PlayingScreen.h"
#include "PlayerGUI.h"
#include "GameGUI.h"
#include "BackgroundGUI.h"
#include <iostream>

void PlayingScreen::playerMove(sf::Time a_time)
{
	//Gestion appui touche
	PlayerGUI* l_player = dynamic_cast<PlayerGUI*>(m_gameObjectManager.get("Player"));
	bool l_noKeyWasPressed = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		l_player->move(PlayerGUI::Up, a_time);
		l_noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		l_player->move(PlayerGUI::Down, a_time);
		l_noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		l_player->move(PlayerGUI::Left, a_time);
		l_noKeyWasPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		l_player->move(PlayerGUI::Right, a_time);
		l_noKeyWasPressed = false;
	}
	if(l_noKeyWasPressed){
		l_player->move(PlayerGUI::None, a_time);
	}
}

PlayingScreen::PlayingScreen()
{
	PlayerGUI *l_player = new PlayerGUI();
	l_player->setPosition(GameGUI::SCREEN_WIDTH / 2, GameGUI::SCREEN_HEIGHT / 2);
	
	BackgroundGUI *l_backgroundGrass = new BackgroundGUI("Ressource/backgroundDarkGrass.png");
	l_backgroundGrass->setPosition(GameGUI::SCREEN_WIDTH / 2, GameGUI::SCREEN_HEIGHT / 2);

	BackgroundGUI *l_tree = new BackgroundGUI("Ressource/pine-tree.png");
	l_tree->setPosition(GameGUI::SCREEN_WIDTH / 2, 150);

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
		sf::Time l_timeDelta = m_gameObjectManager.restartClock();
		a_window.clear(sf::Color(0, 0, 0));

		if (l_currentEvent.type == sf::Event::Closed) {
			return Exit;
		}

		if (l_currentEvent.type == sf::Event::KeyPressed)
		{
			if (l_currentEvent.key.code == sf::Keyboard::Escape) {
				return ReturnMenu;
			}
		}

		m_gameObjectManager.updateAll(l_timeDelta);
		m_gameObjectManager.drawAll(a_window);

		playerMove(l_timeDelta);

		

		a_window.display();
	}
}

const GameObjectManager & PlayingScreen::getGameObjectManager()
{
	return PlayingScreen::m_gameObjectManager;
}

GameObjectManager PlayingScreen::m_gameObjectManager;