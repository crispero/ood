#pragma once
#include "CShapeDecorator.h"

class CTriangle : public CShapeDecorator
{
public:
	CTriangle(sf::ConvexShape& triangle, sf::Vector2f& vertex1, sf::Vector2f& vertex2, sf::Vector2f& vertex3);
	~CTriangle() = default;

	float GetArea() const override;
	float GetPerimeter() const override;
	void PrintInfo(std::ostream& fout) const override;
	void Draw() const override;

private:
	sf::ConvexShape m_triangle;

	float GetSide(sf::Vector2f firstVertex, sf::Vector2f secondVertex) const;

	sf::Vector2f m_vertex1;
	sf::Vector2f m_vertex2;
	sf::Vector2f m_vertex3;
};
