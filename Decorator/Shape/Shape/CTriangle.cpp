#include "CTriangle.h"

CTriangle::CTriangle(sf::ConvexShape& triangle, sf::Vector2f& vertex1, sf::Vector2f& vertex2, sf::Vector2f& vertex3)
	: CShapeDecorator(triangle)
	, m_triangle(triangle)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

float CTriangle::GetArea() const
{
	float firstSide = GetSide(m_vertex1, m_vertex2);
	float secondSide = GetSide(m_vertex2, m_vertex3);
	float thirdSide = GetSide(m_vertex3, m_vertex1);

	float halfPerimeter = (firstSide + secondSide + thirdSide) / 2;
	float area = sqrt(halfPerimeter * (halfPerimeter - firstSide) * (halfPerimeter - secondSide) * (halfPerimeter - thirdSide));
	return area;
}

float CTriangle::GetPerimeter() const
{
	float firstSide = GetSide(m_vertex1, m_vertex2);
	float secondSide = GetSide(m_vertex2, m_vertex3);
	float thirdSide = GetSide(m_vertex3, m_vertex1);

	float perimeter = firstSide + secondSide + thirdSide;
	return perimeter;
}

void CTriangle::PrintInfo(std::ostream& fout) const
{
	fout << TRIANGLE << SPACE << AREA << GetArea() << SPACE << PERIMETER << GetPerimeter() << std::endl;
}

void CTriangle::Draw() const
{
	CCanvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT);
	canvas.DrawTriangle(m_triangle, m_vertex1, m_vertex2, m_vertex3);
}

float CTriangle::GetSide(sf::Vector2f firstVertex, sf::Vector2f secondVertex) const
{
	return (sqrt(pow(secondVertex.x - firstVertex.x, 2) + pow(secondVertex.y - firstVertex.y, 2)));
}