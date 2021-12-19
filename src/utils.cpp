#include "utils.hpp"
#include "elements/Element.hpp"
#include "factories/ElementFactory.hpp"

void drawElement(Matrix* matrix, int brushSize, const int x, const int y, const int width, const int height, byte element) {
	for (int i = x - brushSize; i < x + brushSize; i++) {
		for (int j = y - brushSize; j < y + brushSize; j++) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				Element* elem = ElementFactory::getInstance()->createElement(element);
				if (matrix->getPosition(i, j)->getId() == ERASER || elem->getId() == ERASER) {
					matrix->setPosition(i, j, elem);
				}
			}
		}
	}
}
