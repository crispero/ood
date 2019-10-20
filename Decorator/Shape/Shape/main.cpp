#include <iostream>
#include <fstream>
#include "CRemoteControl.h"
#include "Const.h"

int main(int argc, char* argv[])
{
/*	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
	} */
	int parametersNumber = argc;

	if (parametersNumber != 2)
	{
		std::cout << ERROR_INVALID_ARGUMENTS << std::endl;
		return 1;
	}

	std::string fileName = argv[1];

	std::ifstream fin(fileName);

	if (!fin.is_open())
	{
		std::cout << ERROR_FAILED_OPEN_FILE << std::endl;
		return 1;
	}

	CRemoteControl remoteControl(fin, std::cout);
	remoteControl.HandleCommand();
	remoteControl.PrintInfo();

	return 0;
}
