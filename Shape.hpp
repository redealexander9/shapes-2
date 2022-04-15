#pragma once
#include <memory>
#include "Canvas.hpp"
#include <cmath>

namespace shapes {

  using easywin::Canvas;
  using easywin::Color;
  using easywin::Point;

  class Shape;
  using ShapePtr = std::shared_ptr<Shape>;

  class Shape {
  protected:
      int xCor;
      int yCor;
      int shapeSize;
      Color shapeColor;
  public:
      
      Shape() {
      xCor = 0;
      yCor = 0;
      shapeSize = 100;
      shapeColor = 3318732560;
  }
      

      Shape(int x, int y, int size, Color color);


      int x() const;
      int y() const;
      int size() const;
      Color color() const;
      void move(int x, int y);
      void resize(int size);
      virtual ShapePtr clone() const = 0; 
      virtual void draw(easywin::Canvas& canvas) const = 0;
      virtual bool contains(int x, int y) const = 0;
  };

}