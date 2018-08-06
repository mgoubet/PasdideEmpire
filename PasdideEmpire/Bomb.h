#pragma once
#include "Item.h"
class Bomb : public Item
{
public:
	Bomb();
	~Bomb();
	virtual void move();
};

