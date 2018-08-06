#pragma once
#include "Character.h"
class NeutralCharacter : public Character
{
public:
	NeutralCharacter();
	~NeutralCharacter();
	virtual void move();
};

