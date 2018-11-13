#include "MainMenu.h"


MainMenu::MenuResult MainMenu::show(sf::RenderWindow& a_window)
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("Ressource/mainmenu.png");
	sf::Sprite sprite(image);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 177;
	exitButton.action = Exit;

	m_menuItems.push_back(playButton);
	m_menuItems.push_back(exitButton);

	a_window.draw(sprite);
	a_window.display();

	return GetMenuResponse(a_window);
}

MainMenu::MenuResult MainMenu::HandleClick(int a_x, int a_y)
{
	std::list<MenuItem>::iterator l_it;

	for (l_it = m_menuItems.begin(); l_it != m_menuItems.end(); l_it++)
	{
		sf::Rect<int> l_menuItemRect = (*l_it).rect;
		if (l_menuItemRect.height + l_menuItemRect.top > a_y
			&& l_menuItemRect.top < a_y
			&& l_menuItemRect.left < a_x
			&& l_menuItemRect.width + l_menuItemRect.left> a_x)
		{
			return (*l_it).action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event l_menuEvent;

	while (true)
	{
		while (window.pollEvent(l_menuEvent))
		{
			if (l_menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(l_menuEvent.mouseButton.x, l_menuEvent.mouseButton.y);
			}
			if (l_menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}