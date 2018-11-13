#include "BackgroundGUI.h"



BackgroundGUI::BackgroundGUI(std::string a_filename)
{
	load(a_filename);
	getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);
}


BackgroundGUI::~BackgroundGUI()
{
}

void BackgroundGUI::update(sf::Time a_time)
{
}
