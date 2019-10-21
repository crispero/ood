#pragma once
#define _USE_MATH_DEFINES
#include "CShapeDecorator.h"

class CCircle : public CShapeDecorator
{
public:
	CCircle(sf::CircleShape& circle, const sf::Vector2f& center, const float radius);
	~CCircle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& fout) const override;
	void Draw() const override;

	float GetRadius() const;

private:
	sf::CircleShape m_circle;
	sf::Vector2f m_center;
	float m_radius;
};

