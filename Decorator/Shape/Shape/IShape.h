#pragma once
#include <fstream>

class IShape
{
public:
	IShape() = default;

	virtual float GetArea() const = 0;
	virtual float GetPerimeter() const = 0;
	virtual void PrintInfo(std::ostream& fout) const = 0;
	virtual void Draw() const = 0;
};