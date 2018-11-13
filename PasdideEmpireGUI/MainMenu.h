#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class MainMenu
{

public:
	enum MenuResult { Nothing, Exit, Play };

	struct MenuItem
	{ 
		public:
			sf::Rect<int> rect;
			MenuResult action;
	};

	MenuResult show(sf::RenderWindow& a_window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& a_window);
	MenuResult HandleClick(int a_x, int a_y);
	std::list<MenuItem> m_menuItems;
};
