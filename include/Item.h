#pragma once
#include <string>
class Item
{
private:
	std::string m_name;
	int m_price;
public:
	virtual void use() = 0;
};

