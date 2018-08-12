#pragma once
#include "Game.h"

class PasdideEmpire
{
private:
	Game m_game;
public:
	PasdideEmpire();
	~PasdideEmpire();
	void createGame();
	void loadGame();
};

