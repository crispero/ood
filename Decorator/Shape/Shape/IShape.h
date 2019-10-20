#pragma once
#include <fstream>

class IShape
{
public:
	IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual void PrintInfo(std::ostream& fout) const = 0;
};