#pragma once
#include <SFML/Graphics.hpp>

class SierpinskiTrian
{
private:
	sf::Vector2f point0;
	sf::Vector2f point1;
	sf::Vector2f point2;
	sf::RenderWindow* window;

	sf::Vertex* vertices;

	void sierpinski(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, unsigned int limit);
	void createVertices(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2);

	inline void SierpinskiTrian::draw()
	{
		
		window->draw(vertices, 3, sf::Triangles);
	}

public:
	SierpinskiTrian(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::RenderWindow* renderWindow);

	inline ~SierpinskiTrian()
	{
		delete vertices;
	}
	

	inline void SierpinskiTrian::drawFractal(unsigned int limit)
	{
		sierpinski(point0, point1, point2, limit);
	}
};

