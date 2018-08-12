#pragma once
#include "Item.h"
#include <vector>
class Inventory
{
private:
	std::vector<Item*> m_content;
	int m_size;
public:
	Inventory();
	~Inventory();
};

