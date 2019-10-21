#pragma once
#include "ICanvas.h"

class CCanvas : public ICanvas
{
public:
	CCanvas(const unsigned int width, const unsigned int height);
	~CCanvas() = default;

	void DrawCircle(sf::CircleShape circle, const sf::Vector2f& center, const float radius) override;
	void DrawTriangle(sf::ConvexShape triangle, const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3) override;
	void DrawRectangle(sf::RectangleShape rectangle, const float width, const float height) override;

private:
	void DrawShape(sf::Shape& shape);

	sf::RenderWindow m_window;
	unsigned int m_width;
	unsigned int m_height;
};

