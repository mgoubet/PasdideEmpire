#pragma once
#include "Character.h"
class Projectile
{
private:
	int m_scope;
public:
	virtual void touchCharacter(Character* a_character) = 0;
};

