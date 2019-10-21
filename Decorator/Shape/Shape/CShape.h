#pragma once
#include "IShape.h"
#include <SFML/Graphics/Shape.hpp>

class CShape : public sf::Shape, public IShape
{
public:
	CShape();
	~CShape();
};

