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

void loadTextures(RenderWindow* window, SDL_Texture** textures) {
	textures[0] = window->loadImage("./res/Eraser.png");
	textures[1] = window->loadImage("./res/Water.png");
	textures[2] = window->loadImage("./res/Acid.png");
	textures[3] = window->loadImage("./res/Sand.png");
	textures[4] = window->loadImage("./res/Wood.png");
	textures[5] = window->loadImage("./res/Stone.png");
	textures[6] = window->loadImage("./res/Vapor.png");
	textures[7] = window->loadImage("./res/Glass.png");
	textures[8] = window->loadImage("./res/Lava.png");
	textures[9] = window->loadImage("./res/Fire.png");
}

void initLabels(string* labels) {
	labels[0] = "Eraser";
	labels[1] = "Water";
	labels[2] = "Acid";
	labels[3] = "Sand";
	labels[4] = "Wood";
	labels[5] = "Stone";
	labels[6] = "Vapor";
	labels[7] = "Glass";
	labels[8] = "Lava";
	labels[9] = "Fire";
}
