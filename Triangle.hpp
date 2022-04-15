#pragma once
#include "Canvas.hpp"
using easywin::Color;
#include "Shape.hpp"
using namespace shapes;


class Triangle : public Shape
{
	Color shapeColor;
public:
	Triangle(int x, int y, int size, Color color) {
		Shape::xCor = x;
		Shape::yCor = y;
		Shape::shapeSize = size;
		shapeColor = color;
	}

	bool contains(int x, int y) const;
	void draw(easywin::Canvas& canvas) const;
	ShapePtr clone() const;


};

