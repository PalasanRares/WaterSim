#include "utils.hpp"

void drawElement(Matrix* matrix, int brushSize, const int x, const int y, const int width, const int height, byte element) {
	for (int i = x - brushSize; i < x + brushSize; i++) {
		for (int j = y - brushSize; j < y + brushSize; j++) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				Element* elem;
				switch (element) {
			    case ERASER:
			      elem = new Eraser();
			      break;
			    case WATER:
			      elem = new Water();
			      break;
			    case ACID:
			      elem = new Acid();
			      break;
					case SAND:
						elem = new Sand();
						break;
					case WOOD:
						elem = new Wood();
						break;
					case STONE:
						elem = new Stone();
						break;
					case VAPOR:
						elem = new Vapor();
						break;
			  }
				if (matrix->getPosition(i, j)->getId() == ERASER || elem->getId() == ERASER) {
					matrix->setPosition(i, j, elem);
				}
			}
		}
	}
}

void loadTextures(RenderWindow* window, SDL_Texture** textures) {
	textures[1] = window->loadImage("./res/Water.png");
	textures[2] = window->loadImage("./res/Acid.png");
	textures[3] = window->loadImage("./res/Sand.png");
	textures[4] = window->loadImage("./res/Wood.png");
	textures[5] = window->loadImage("./res/Stone.png");
	textures[6] = window->loadImage("./res/Vapor.png");
}
