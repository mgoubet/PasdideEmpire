#pragma once
#include "Projectile.h"
class Fireball : public Projectile
{
public:
	Fireball();
	~Fireball();
	virtual void touchCharacter(Character* a_character);
};

