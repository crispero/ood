#include "CRectangle.h"

CRectangle::CRectangle(sf::RectangleShape& rectangle, sf::Vector2f& leftTop, sf::Vector2f& rightBottom)
	: CShapeDecorator(rectangle)
	, m_rectangle(rectangle)
	, m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
}

double CRectangle::GetArea() const
{
	return GetHeight() * GetWidth();
}

double CRectangle::GetPerimeter() const
{
	return (GetHeight() + GetWidth()) * 2;
}

double CRectangle::GetWidth() const
{
	return std::abs(m_rightBottom.x - m_leftTop.x);
}

double CRectangle::GetHeight() const
{
	return std::abs(m_leftTop.y - m_rightBottom.y);
}

void CRectangle::PrintInfo(std::ostream& fout) const
{
	fout << RECTANGLE << SPACE << AREA << GetArea() << SPACE << PERIMETER << GetPerimeter() << std::endl;
}