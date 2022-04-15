#pragma once
#include "Canvas.hpp"
#include "Shape.hpp"
using namespace shapes;
using easywin::Color;

class Circle : public Shape
{
	int shapeColor;
public:
	Circle(int x, int y, int size, Color color) {
		Shape::xCor = x;
		Shape::yCor = y;
		Shape::shapeSize = size;
		shapeColor = color;
	}

	bool contains(int x, int y) const;
	void draw(easywin::Canvas& canvas) const;
	ShapePtr clone() const;
};