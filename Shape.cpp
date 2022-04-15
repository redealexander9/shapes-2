#include <iostream>
#include "Shape.hpp"
#include "Square.hpp"


shapes::Shape::Shape(int x, int y, int size, Color color) 
{
	Shape::xCor = x;
	Shape::yCor = y;
	Shape::shapeSize = size;
	Shape::shapeColor = color;
}

int shapes::Shape::x() const
{
	return this->xCor;
}

int shapes::Shape::y() const
{
	return this->yCor;
}

int shapes::Shape::size() const
{
	return this->shapeSize;
}

easywin::Color shapes::Shape::color() const
{
	return Color();
}

void shapes::Shape::move(int x, int y)
{
		Shape::yCor = y;
		Shape::xCor = x;
}

void shapes::Shape::resize(int size)
{
	if (size < 10) {
		this->shapeSize = 10;
	}
	else if (size > 500) {
		this->shapeSize = 500;
	}
	else {
		this->shapeSize = size;
	}
}


