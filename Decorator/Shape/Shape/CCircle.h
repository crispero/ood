#pragma once
#define _USE_MATH_DEFINES
#include "CShapeDecorator.h"
#include <cmath>

class CCircle : public CShapeDecorator
{
public:
	CCircle(sf::CircleShape& circle, const sf::Vector2f& center, const double& radius);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	void PrintInfo(std::ostream& fout) const override;

	double GetRadius() const;

private:
	sf::CircleShape m_circle;
	sf::Vector2f m_center;
	double m_radius;
};

