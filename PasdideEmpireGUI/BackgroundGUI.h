#pragma once
#include "VisibleGameObject.h"

class BackgroundGUI : public VisibleGameObject
{
public:
	BackgroundGUI(std::string a_filename);
	~BackgroundGUI();

	void update(sf::Time a_time);
};

