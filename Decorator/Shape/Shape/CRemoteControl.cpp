#include "CRemoteControl.h"
#include "Const.h"
#include "IShape.h"
#include <sstream>

CRemoteControl::CRemoteControl(std::istream& input, std::ostream& output)
	: m_input(input)
	, m_output(output)
{
}

void CRemoteControl::HandleCommand()
{
	std::string commandLine;
	while (std::getline(m_input, commandLine))
	{
		std::istringstream ist(commandLine);
		std::string shapeName;
		ist >> shapeName;
		std::shared_ptr<CShapeDecorator> shapeDecorator;

		if (shapeName == CIRCLE)
		{
			shapeDecorator = CreateCircle(ist);
			m_shape.push_back(shapeDecorator);
		}
		else if (shapeName == RECTANGLE)
		{
			shapeDecorator = CreateRectangle(ist);
			m_shape.push_back(shapeDecorator);
		}
		else if (shapeName == TRIANGLE)
		{
		//	shapeDecorator = CreateTriangle(ist);
		//	m_shape.push_back(shapeDecorator);
		}
		else
		{
			m_output << ERROR_UNKNOWN_FIGURE << std::endl;
		}
	}
}

std::shared_ptr<CCircle> CRemoteControl::CreateCircle(std::istream& ist)
{
	sf::CircleShape circle;
	double centerX, centerY, radius;

	ist >> centerX >> centerY >> radius;

	sf::Vector2f center(centerX, centerY);
	
	return std::make_shared<CCircle>(circle, center, radius);
}

std::shared_ptr<CRectangle> CRemoteControl::CreateRectangle(std::istream& ist)
{
	sf::RectangleShape rectangle;
	double leftTopX, leftTopY, rightBottomX, rightBottomY;

	ist >> leftTopX >> leftTopY >> rightBottomX >> rightBottomY;

	sf::Vector2f leftTop(leftTopX, leftTopY);
	sf::Vector2f rightBottom(rightBottomX, rightBottomY);

	return std::make_shared<CRectangle>(rectangle, leftTop, rightBottom);
}

std::shared_ptr<CTriangle> CRemoteControl::CreateTriangle(std::istream& ist)
{
	double x1, y1;
	double x2, y2;
	double x3, y3;

	ist >> x1 >> y1;
	ist >> x2 >> y2;
	ist >> x3 >> y3;

	sf::Vector2f vertex1(x1, y1);
	sf::Vector2f vertex2(x2, y2);
	sf::Vector2f vertex3(x3, y3);

	return std::make_shared<CTriangle>();
}


void CRemoteControl::PrintInfo()
{
	if (m_shape.size() == 0)
	{
		m_output << ERROR_NO_FIGURES_FOUND;
	}
	else 
	{
		for (auto shape : m_shape)
		{
			shape->PrintInfo(m_output);
		}
	}
}