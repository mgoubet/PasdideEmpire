#pragma once
#include "FightingCharacter.h"

class EnnemyCharacter
{
public:
	EnnemyCharacter();
	~EnnemyCharacter();
	virtual void move(int a_x, int a_y);
};

