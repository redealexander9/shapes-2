#include "ShapeManager.hpp"
#include <stdexcept>
#include <algorithm>
using std::make_shared;

namespace shapes {
    const std::map<ShapeManager::ShapeType, std::string> ShapeManager::shapeTypes = {
      { ShapeManager::ShapeType::Square,   "Square"  },
      { ShapeManager::ShapeType::Circle,   "Circle"  },
      { ShapeManager::ShapeType::Triangle, "Triangle"}
    };

    // Write your methods here:
    ShapePtr ShapeManager::makeShape(ShapeType type, int x, int y, int size, Color color)     // factory function
    {
        if (type == ShapeType::Square) {
            std::shared_ptr<Square> s = make_shared<Square>(x, y, size, color);
            return s;
        }
        else if (type == ShapeType::Circle) {
            std::shared_ptr<Circle> c = make_shared<Circle>(x, y, size, color);
            return c;
        }
        else {
            std::shared_ptr<Triangle> t = make_shared<Triangle>(x, y, size, color);
            return t;
        }
    }

    void ShapeManager::addShape(ShapePtr shape)
    {
        shapes.push_back(shape);
    }

    ShapePtr ShapeManager::select(int x, int y)
    {
            for (int i = shapes.size() - 1; i >= 0; i--) {
                if (shapes[i] != NULL && shapes.size() > 0) {
                    if (shapes.at(i)->contains(x, y)) {
                        if (i == shapes.size()) {
                            return shapes.at(i);
                        }
                        else {
                            std::swap(shapes[i], shapes.back());
                            return shapes.at(shapes.size() - 1);
                        }
                    }
                }
                else {
                    return nullptr;
                }
            }
            if (shapes.size() == 1 && shapes.at(0)->contains(x, y)) {
                return shapes.at(0);
            }


        return nullptr;

    }

    void ShapeManager::drawShapes(Canvas& canvas) const
    {

        if (shapes.size() > 0) {
            
            for (int i = 0; i < shapes.size(); i++) {
                if (shapes[i] != NULL) {
                    shapes.at(i)->draw(canvas);
              }
           }
        }

    }  
}   // namespace shapes