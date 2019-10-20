#pragma once
#include <SFML/Graphics.hpp>

class ICanvas
{
public:
	ICanvas() = default;
	virtual ~ICanvas() = default;

	virtual void DrawCircle() = 0;
	virtual void DrawTriangle() = 0;
	virtual void DrawRectangle() = 0;
};