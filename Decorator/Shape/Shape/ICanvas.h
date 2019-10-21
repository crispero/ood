#pragma once
#include <SFML/Graphics.hpp>

class ICanvas
{
public:
	ICanvas() = default;
	virtual ~ICanvas() = default;

	virtual void DrawCircle(sf::CircleShape circle, const sf::Vector2f& center, const float radius) = 0;
	virtual void DrawTriangle(sf::ConvexShape triangle, const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3) = 0;
	virtual void DrawRectangle(sf::RectangleShape rectangle, const float width, const float height) = 0;
};