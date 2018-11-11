#include "GameGUI.h"
#include "MainMenu.h"

void GameGUI::start(void)
{
	if (m_gameState != Uninitialized)
		return;

	m_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pasdide Empire", sf::Style::Fullscreen);

	//_mainWindow.setFramerateLimit(60);

	m_gameState = GameGUI::ShowingSplash;


	while (!isExiting())
	{
		gameLoop();
	}

	m_mainWindow.close();
}

bool GameGUI::isExiting()
{
	if (m_gameState == GameGUI::Exiting)
		return true;
	else
		return false;
}


sf::RenderWindow& GameGUI::getWindow()
{
	return m_mainWindow;
}

const sf::Event& GameGUI::getInput()
{
	sf::Event currentEvent;
	m_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}

const GameObjectManager& GameGUI::getGameObjectManager()
{
	return GameGUI::m_gameObjectManager;
}

void GameGUI::gameLoop()
{
	sf::Event currentEvent;
	m_mainWindow.pollEvent(currentEvent);


	switch (m_gameState)
	{
	case GameGUI::ShowingMenu:
	{
		showMenu();
		break;
	}
	case GameGUI::ShowingSplash:
	{
		showSplashScreen();
		break;
	}
	case GameGUI::Playing:
	{
		m_mainWindow.clear(sf::Color(0, 0, 0));

		m_gameObjectManager.updateAll();
		m_gameObjectManager.drawAll(m_mainWindow);
		
		m_mainWindow.display();
		if (currentEvent.type == sf::Event::Closed) m_gameState = GameGUI::Exiting;

		if (currentEvent.type == sf::Event::KeyPressed)
		{
			if (currentEvent.key.code == sf::Keyboard::Escape) showMenu();
		}

		break;
	}
	}
}

void GameGUI::showSplashScreen()
{
	/*SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);*/
	m_gameState = GameGUI::ShowingMenu;
}

void GameGUI::showMenu()
{
	MainMenu l_mainMenu;
	MainMenu::MenuResult l_result = l_mainMenu.Show(m_mainWindow);
	switch (l_result)
	{
		case MainMenu::Exit:
			m_gameState = Exiting;
			break;
		case MainMenu::Play:
			m_gameState = Playing;
			break;
	}
}

GameGUI::GameState GameGUI::m_gameState = Uninitialized;
sf::RenderWindow GameGUI::m_mainWindow;
GameObjectManager GameGUI::m_gameObjectManager;