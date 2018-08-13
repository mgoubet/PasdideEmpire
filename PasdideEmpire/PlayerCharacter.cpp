#include "stdafx.h"
#include "PlayerCharacter.h"
#include <algorithm>

PlayerCharacter::PlayerCharacter()
{
}

PlayerCharacter::PlayerCharacter(int a_x, int a_y, std::string a_name, Job * a_currentJob, int a_hpMax, int a_currentHp, int a_lvl, int a_expMax, int a_currentExp, Inventory a_inv)
	: FightingCharacter(a_x, a_y, a_name, a_currentJob, a_hpMax, a_currentHp, a_lvl)
{
	m_expMax = a_expMax;
	m_currentExp = a_currentExp;
	m_inventory = a_inv;
	m_jobAvailable.push_back(a_currentJob->getName());
}


PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::unlockJob(const std::string& a_jobName)
{
	if (std::find(m_jobAvailable.begin(), m_jobAvailable.end(), a_jobName) == m_jobAvailable.end()) {
		m_jobAvailable.push_back(a_jobName);
	}
}


void PlayerCharacter::changeJob(Job* a_job)
{
	if (std::find(m_jobAvailable.begin(), m_jobAvailable.end(), a_job->getName()) != m_jobAvailable.end()) {
		delete(m_job);
		m_job = a_job;
	}
}

void PlayerCharacter::move(int a_x, int a_y)
{
	m_x += a_x;
	m_y += a_y;
}
