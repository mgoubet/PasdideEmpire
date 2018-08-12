#pragma once
#include <vector>
#include <string>
class Case
{
private:
	std::vector<int> m_position;
	std::string m_content;
public:
	Case();
	~Case();
	
	std::vector<int> getCoordinate();
	std::vector<int> getPosition();
	void setPosition(std::vector<int> a_position);
};

