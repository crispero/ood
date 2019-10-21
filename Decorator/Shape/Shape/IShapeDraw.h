#pragma once
#include "ICanvas.h"

class IShapeDraw
{
public:
	IShapeDraw() = default;

	virtual void Draw(ICanvas& canvas) const = 0;
};