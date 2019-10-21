#pragma once
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCanvas.h"

class CRemoteControl
{
public:
	CRemoteControl(std::istream& fin, std::ostream& fout);
	void HandleCommand();
	void PrintInfo();
	void DrawShapes();

private:
	std::shared_ptr<CCircle> CreateCircle(std::istream& ist);
	std::shared_ptr<CRectangle> CreateRectangle(std::istream& ist);
	std::shared_ptr<CTriangle> CreateTriangle(std::istream& ist);

private:
	std::istream& m_input;
	std::ostream& m_output;

	std::vector<std::shared_ptr<CShapeDecorator>> m_shapes;
};

