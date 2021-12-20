#include "Drawer.hpp"
#include "Matrix.hpp"
#include "elements/Element.hpp"
#include "factories/ElementFactory.hpp"

#include <iostream>

void Drawer::modifyBrushSize(const int& increment) {
  if ((brushSize < maxBrushSize && increment > 0) || (brushSize > 1 && increment < 0)) {
    brushSize += increment;
  }
}

void Drawer::drawElement(Matrix* matrix, const int& x, const int& y, const int& element) {
  for (int i = x - brushSize; i <= x + brushSize; i++) {
		for (int j = y - brushSize; j <= y + brushSize; j++) {
      if ((((i - x) * (i - x) + (j - y) * (j - y)) <= brushSize * brushSize) && (matrix->checkPosition(i, j))) {
        Element* elem = ElementFactory::getInstance()->createElement(element);
        if (matrix->getPosition(i, j)->getId() == ERASER || elem->getId() == ERASER) {
					matrix->setPosition(i, j, elem);
				}
      }
		}
	}
}

const int& Drawer::getBrushSize() {
  return brushSize;
}
