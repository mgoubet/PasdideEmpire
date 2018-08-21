#include <SFML/Graphics.hpp>
#include "../PasdideEmpire/PlayerCharacter.h"
#include "../PasdideEmpire/WarriorJob.h"

int main()
{
	PlayerCharacter l_player(0, 0, std::string(), new WarriorJob(), 0, 0, 0, 0, 0, Inventory());
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}