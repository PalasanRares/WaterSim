#include "Eraser.hpp"

#include "ElementManager.hpp"

Eraser::Eraser() : Element(ERASER, 0, rgb(0, 0, 0)) {};

void Eraser::update(Matrix* matrix, const int& i, const int& j) const {
  return;
}
