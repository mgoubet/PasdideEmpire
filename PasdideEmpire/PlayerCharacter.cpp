#include "stdafx.h"
#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter()
{
}

PlayerCharacter::PlayerCharacter(int a_x, int a_y, std::string a_name, Job * a_currentJob, int a_hpMax, int a_currentHp, int a_lvl, int a_expMax, int a_currentExp, Inventory a_inv)
	: FightingCharacter(a_x, a_y, a_name, a_currentJob, a_hpMax, a_currentHp, a_lvl)
{
	m_expMax = a_expMax;
	m_currentExp = a_currentExp;
	m_inventory = a_inv;
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::changeJob()
{
}

void PlayerCharacter::move(int a_x, int a_y)
{
	m_x += a_x;
	m_y += a_y;
}
