#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	
	//shape.setFillColor(sf::Color::Green);

	sf::Vertex line[2];
	line[0].position = sf::Vector2f(0, 0);
	line[1].position = sf::Vector2f(300, 300);
	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(line, 2, sf::Lines);
		window.display();
	}

	return 0;
}