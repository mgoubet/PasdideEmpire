#pragma once
#include "GameObjectManager.h"

class PlayingScreen
{
private:
	static GameObjectManager m_gameObjectManager;
public:
	enum PlayingResult { Nothing, ReturnMenu, Exit, Play, Pause };
	PlayingScreen();
	~PlayingScreen();
	PlayingResult show(sf::RenderWindow& a_window);
	const static GameObjectManager& getGameObjectManager();
};

