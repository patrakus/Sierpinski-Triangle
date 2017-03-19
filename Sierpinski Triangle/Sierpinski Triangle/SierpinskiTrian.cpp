#include "SierpinskiTrian.h"



void SierpinskiTrian::sierpinski(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, unsigned int limit)
{
	if (limit > 0)
	{
		sf::Vector2f pA((p0.x + p1.x) / 2.f, (p0.y + p1.y) / 2.f);
		sf::Vector2f pB((p1.x + p2.x) / 2.f, (p1.y + p2.y) / 2.f);
		sf::Vector2f pC((p2.x + p0.x) / 2.f, (p2.y + p0.y) / 2.f);

		sierpinski(p0, pA, pC, limit - 1);
		sierpinski(pA, p1, pB, limit - 1);
		sierpinski(pC, pB, p2, limit - 1);
	}
	else
	{
		createVertices(p0, p1, p2);
		draw();
	}
}

void SierpinskiTrian::createVertices(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2)
{
	vertices[0].position = p0;
	vertices[1].position = p1;
	vertices[2].position = p2;
}

SierpinskiTrian::SierpinskiTrian(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::RenderWindow* renderWindow) :
	point0(p0), point1(p1), point2(p2)
{
	vertices = new sf::Vertex[3];
	vertices[0].color = sf::Color::Red;
	vertices[1].color = sf::Color::Red;
	vertices[2].color = sf::Color::Red;
	window = renderWindow;
}