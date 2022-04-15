#include "Triangle.hpp"
#include <vector>

bool Triangle::contains(int x, int y) const
{
	int top = Shape::xCor;
	int bottom = Shape::yCor + Shape::shapeSize;
	int x1 = Shape::xCor + (Shape::shapeSize / 2);
	int y1 = Shape::yCor;
	int slope;
	if (x - x1 == 0) {
		slope = 0;
	}
	else {
		slope = (y - y1) / (x - x1);
	}

	if ((y >= Shape::yCor && y <= Shape::yCor + Shape::shapeSize) && (slope >= 2 || slope <= -2)) {
		return true;
	}
	else {
		return false;
	}
}

void Triangle::draw(easywin::Canvas& canvas) const
{
	Point a = { Shape::xCor + (Shape::shapeSize / 2), Shape::yCor};
	Point b = { Shape::xCor, Shape::yCor + Shape::shapeSize};
	Point c = { Shape::xCor + Shape::shapeSize, Shape::yCor + Shape::shapeSize };
	std::vector<Point> tri = {a, b, c};
	canvas.drawPolygon(tri, 0, shapeColor);
}

ShapePtr Triangle::clone() const
{


	std::shared_ptr<Triangle> t = std::make_shared<Triangle>(Shape::xCor, Shape::yCor, Shape::shapeSize, shapeColor);


	return t;
}
