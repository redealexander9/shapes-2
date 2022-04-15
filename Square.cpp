#include "Square.hpp"

bool Square::contains(int x, int y) const
{
	if (x > Shape::xCor && x < Shape::shapeSize + Shape::xCor && y > Shape::yCor && y < Shape::shapeSize + Shape::yCor) {
		return true;
	}
	else {
		return false;
	}
}

void Square::draw(easywin::Canvas& canvas) const
{
	int size = Shape::shapeSize;
	int left = Shape::xCor;
	int top = Shape::yCor;
	int right = Shape::xCor + size;
	int bottom = Shape::yCor + size;
	canvas.drawRectangle(left, top, right, bottom, 0, shapeColor);
}

shapes::ShapePtr Square::clone() const
{
	std::shared_ptr<Square> s = std::make_shared<Square>(Shape::xCor, Shape::yCor, Shape::shapeSize, shapeColor);

	return s;

}
