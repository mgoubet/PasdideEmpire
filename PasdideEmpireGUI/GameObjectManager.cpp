#include "GameObjectManager.h"
#include "GameGUI.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(m_gameObjects.begin(), m_gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(std::string a_name, VisibleGameObject* a_gameObject)
{
	m_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(a_name, a_gameObject));
}

void GameObjectManager::remove(std::string a_name)
{
	std::map<std::string, VisibleGameObject*>::iterator l_results = m_gameObjects.find(a_name);
	if (l_results != m_gameObjects.end())
	{
		delete l_results->second;
		m_gameObjects.erase(l_results);
	}
}

VisibleGameObject* GameObjectManager::get(std::string a_name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator l_results = m_gameObjects.find(a_name);
	if (l_results == m_gameObjects.end())
		return NULL;
	return l_results->second;

}

int GameObjectManager::getObjectCount() const
{
	return m_gameObjects.size();
}


void GameObjectManager::drawAll(sf::RenderWindow& renderWindow)
{

	std::map<std::string, VisibleGameObject*>::const_iterator l_itr = m_gameObjects.begin();
	while (l_itr != m_gameObjects.end())
	{
		l_itr->second->draw(renderWindow);
		l_itr++;
	}
}

void GameObjectManager::updateAll()
{
	std::map<std::string, VisibleGameObject*>::const_iterator l_itr = m_gameObjects.begin();
	float l_timeDelta = m_clock.restart().asSeconds();

	while (l_itr != m_gameObjects.end())
	{
		l_itr->second->update(l_timeDelta);
		l_itr++;
	}


}