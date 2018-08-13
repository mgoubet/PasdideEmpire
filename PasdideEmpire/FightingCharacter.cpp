#include "stdafx.h"
#include "FightingCharacter.h"


FightingCharacter::FightingCharacter()
{
}

FightingCharacter::FightingCharacter(int a_x, int a_y, std::string a_name, Job * a_job, int a_hpMax, int a_currentHp, int a_lvl) :
	Character(a_x, a_y, a_name)
{
	m_job = a_job;
	m_hpMax = a_hpMax;
	m_currentHp = a_currentHp;
	m_level = a_lvl;

}


FightingCharacter::~FightingCharacter()
{
}

void FightingCharacter::takeDammage(int a_dammage)
{
	m_currentHp -= a_dammage;
}

void FightingCharacter::heal(int a_heal)
{
	m_currentHp += a_heal;
	if (m_currentHp > m_hpMax) {
		m_currentHp = m_hpMax;
	}
}
