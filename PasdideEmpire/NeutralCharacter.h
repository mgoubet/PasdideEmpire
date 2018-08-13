#pragma once
#include "Character.h"
class NeutralCharacter : public Character
{
public:
	NeutralCharacter();
	~NeutralCharacter();
	virtual void move(int a_x, int a_y);
};

