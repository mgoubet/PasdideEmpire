#pragma once
#include "Projectile.h"
class Arrow : public Projectile
{
public:
	Arrow();
	~Arrow();
	virtual void touchCharacter(Character* a_character);
};

