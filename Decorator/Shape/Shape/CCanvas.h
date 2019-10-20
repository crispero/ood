#pragma once
#include "ICanvas.h"

class CCanvas : public ICanvas
{
public:
	CCanvas(size_t width, size_t height);
	~CCanvas() = default;

	//void DrawCircle() override;
//	void DrawTriangle() override;
	//void DrawRectangle() override;

private:
	sf::RenderWindow m_window;
	size_t m_width;
	size_t m_height;
};

