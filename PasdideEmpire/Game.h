#pragma once
#include "Map.h"
class Game
{
private:
	Map m_currentMap;
	Character* m_mainPlayer;
public:
	Game();
	Game(Map a_map, Character* a_mainPlayer);
	~Game();

	void changeMap(Map a_map);
};

