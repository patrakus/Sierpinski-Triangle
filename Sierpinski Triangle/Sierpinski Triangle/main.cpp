#include <SFML/Graphics.hpp>
#include "SierpinskiTrian.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	
	//shape.setFillColor(sf::Color::Green);

	SierpinskiTrian sierpinskiTriangle(sf::Vector2f(400.f, 200.f), sf::Vector2f(600.f, 400.f), sf::Vector2f(200.f, 400.f), &window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(line, 3, sf::Triangles);
		sierpinskiTriangle.drawFractal(5);
		window.display();
	}

	return 0;
}