#include "CCircle.h"

CCircle::CCircle(sf::CircleShape& circle, const sf::Vector2f& center, const float radius)
	: CShapeDecorator(circle)
	, m_circle(circle)
	, m_center(center)
	, m_radius(radius)
{
}

float CCircle::GetArea() const
{
	return float(M_PI * GetRadius() * GetRadius());
}

float CCircle::GetPerimeter() const
{
	return float(2 * M_PI * GetRadius());
}

void CCircle::PrintInfo(std::ostream& fout) const
{
	fout << CIRCLE << SPACE << AREA << GetArea() << SPACE << PERIMETER << GetPerimeter() << std::endl;
}

void CCircle::Draw() const
{
	CCanvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT);
	canvas.DrawCircle(m_circle, m_center, m_radius);
}

float CCircle::GetRadius() const
{
	return m_radius;
}