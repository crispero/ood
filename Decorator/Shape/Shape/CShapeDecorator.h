#pragma once
#include "IShape.h"
#include "ICanvas.h"
#include "CCanvas.h"
#include "Const.h"
#include <cmath>

class CShapeDecorator : public sf::Shape, public IShape
{
public:
	CShapeDecorator(sf::Shape& shape);
	~CShapeDecorator() = default;

    std::size_t sf::Shape::getPointCount() const;
	sf::Vector2f sf::Shape::getPoint(std::size_t index) const;

protected:
	sf::Shape& m_shape;
};

