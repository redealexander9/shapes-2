#include "Circle.hpp"


void Circle::draw(easywin::Canvas& canvas) const
{
	easywin::Point center = { Shape::xCor + (Shape::shapeSize / 2), Shape::yCor + (Shape::shapeSize / 2)};
	int radius = Shape::shapeSize / 2;
	canvas.drawEllipse(center, radius, 0, shapeColor);
}

ShapePtr Circle::clone() const
{
	std::shared_ptr<Circle> c = std::make_shared<Circle>(Shape::xCor, Shape::yCor, Shape::shapeSize, shapeColor);


	return ShapePtr();
}


bool Circle::contains(int x1, int y1) const {
	int x2 = Shape::xCor + (Shape::shapeSize / 2);
	int y2 = Shape::yCor + (Shape::shapeSize / 2);
	int xPoint = std::pow((x1 - x2), 2);
	int yPoint = std::pow((y1 - y2), 2);
	int distance = xPoint + yPoint;
	distance = std::sqrt(distance);
	if (distance < (Shape::shapeSize / 2)) {
		return true;
	}
	else {
		return false;
	}
}