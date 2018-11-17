#pragma once
#include "AnimatedVisibleGameObject.h"
#include "../PasdideEmpire/PlayerCharacter.h"
class PlayerGUI : public AnimatedVisibleGameObject 
{
private:
	PlayerCharacter m_playerCharacter;
	void load(std::string a_filename);
	bool collide();
public:
	PlayerGUI();
	~PlayerGUI();
	enum PlayerAction {
		Up, Down, Left, Right, None
	};

	void move(PlayerAction a_action, sf::Time a_time, float a_speed = 80.f);

	void update(sf::Time a_time);
};

