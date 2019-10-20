#include "CShapeDecorator.h"


CShapeDecorator::CShapeDecorator(sf::Shape& shape)
	: m_shape(shape)
{
}

std::size_t CShapeDecorator::getPointCount() const
{
	return m_shape.getPointCount();
}

sf::Vector2f CShapeDecorator::getPoint(std::size_t index) const
{
	return m_shape.getPoint(index);
}
