#pragma once
#include "CPoint.h"
#include "CShape.h"
#include "CShapeDecorator.h"
#include <sstream>
#include <algorithm>

class CRectangle : public CShapeDecorator
{
public:
	CRectangle(sf::RectangleShape& rectangle, sf::Vector2f& leftTop, sf::Vector2f& rightBottom);
	~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	void PrintInfo(std::ostream& fout) const override;

	double GetWidth() const;
	double GetHeight() const;
	
private:
	sf::RectangleShape m_rectangle;

	sf::Vector2f m_leftTop;
	sf::Vector2f m_rightBottom;
};
