#pragma once
#include "VisibleGameObject.h"
#include "AnimatedVisibleGameObject.h"
#include <string>
class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void add(std::string a_name, VisibleGameObject* a_gameObject);
	void remove(std::string a_name);
	int getObjectCount() const;
	VisibleGameObject* get(std::string a_name) const;

	void drawAll(sf::RenderWindow& a_renderWindow);
	void updateAll();

private:
	std::map<std::string, VisibleGameObject*> m_gameObjects;

	sf::Clock m_clock;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> & a_p) const
		{
			delete a_p.second;
		}
	};
};