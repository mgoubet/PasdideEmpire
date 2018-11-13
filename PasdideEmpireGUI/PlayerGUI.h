#pragma once
#include "AnimatedVisibleGameObject.h"
#include "../PasdideEmpire/PlayerCharacter.h"
class PlayerGUI : public AnimatedVisibleGameObject 
{
private:
	PlayerCharacter m_playerCharacter;
	void load(std::string a_filename);
public:
	PlayerGUI();
	~PlayerGUI();

	void update(sf::Time a_time);
};

