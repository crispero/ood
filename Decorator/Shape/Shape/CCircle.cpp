#include "CCircle.h"

CCircle::CCircle(sf::CircleShape& circle, const sf::Vector2f& center, const double& radius)
	: CShapeDecorator(circle)
	, m_circle(circle)
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return M_PI * GetRadius() * GetRadius();
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * GetRadius();
}

void CCircle::PrintInfo(std::ostream& fout) const
{
	fout << CIRCLE << SPACE << AREA << GetArea() << SPACE << PERIMETER << GetPerimeter() << std::endl;
}

double CCircle::GetRadius() const
{
	return m_radius;
}