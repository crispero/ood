#include "CCanvas.h"

CCanvas::CCanvas(const unsigned int width, const unsigned int height)
	: m_width(width)
	, m_height(height)
{
}

void CCanvas::DrawShapes(const std::vector<std::shared_ptr<CShapeDecorator>>& shapes)
{
	m_window.create(sf::VideoMode(m_width, m_height), WINDOW_NAME);

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
		m_window.clear();
		for (auto shape : shapes)
		{
			shape->Draw(*this);
		}
		m_window.display();
	}
}

void CCanvas::DrawCircle(sf::CircleShape circle, const sf::Vector2f& center, const float radius)
{
	circle.setFillColor(sf::Color::Blue);
	circle.setRadius(radius);
	m_window.draw(circle);
}

void CCanvas::DrawTriangle(sf::ConvexShape triangle, const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3)
{
	triangle.setFillColor(sf::Color::Red);

	triangle.setPointCount(3);
	triangle.setPoint(0, vertex1);
	triangle.setPoint(1, vertex2);
	triangle.setPoint(2, vertex3);

	m_window.draw(triangle);
}

void CCanvas::DrawRectangle(sf::RectangleShape rectangle, const float width, const float height)
{
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setSize(sf::Vector2f(width, height));
	m_window.draw(rectangle);
}