#pragma once
#include "Canvas.hpp"
#include "Shape.hpp"
#include "Shape.hpp"

class Square : public shapes::Shape
{
	easywin::Color shapeColor;

public:
	
	Square(int x, int y, int size, easywin::Color color) {
		Shape::xCor = x;
		Shape::yCor = y;
		Shape::shapeSize = size;
		shapeColor = color;
	}


	bool contains(int x, int y) const;

	void draw(easywin::Canvas& canvas) const;
	shapes::ShapePtr clone() const;

};

