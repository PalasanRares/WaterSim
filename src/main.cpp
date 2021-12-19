#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>

#include "RenderWindow.hpp"
#include "elements/liquids/Water.hpp"
#include "elements/Eraser.hpp"
#include "elements/Element.hpp"
#include "elements/liquids/Liquid.hpp"
#include "elements/liquids/Acid.hpp"
#include "Matrix.hpp"
#include "utils.hpp"
#include "types.hpp"
#include "AssetManager.hpp"

using namespace std;

int main(int argc, char** argv) {
	const char* title = "WaterSim 0.9";
	const int width = 250;
	const int height = 125;
	int brushSize = 1;
	byte element = 1;
	byte elementNr = 10;
	RenderWindow* window = new RenderWindow(title, width * 4, height * 4);
	bool running = true;

	Matrix* matrix = new Matrix(width, height);

	SDL_Event event;

	int xMouse, yMouse;

	while (running) {
		uint32_t time = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_RIGHT:
							if (brushSize < 3) {
								brushSize += 1;
							}
							break;
						case SDLK_LEFT:
							if (brushSize > 1) {
								brushSize -= 1;
							}
							break;
						case SDLK_UP:
							element = (element + 1) % elementNr;
							break;
						case SDLK_DOWN:
							if (element == 0) {
								element = elementNr - 1;
							}
							else {
								element = (element - 1) % elementNr;
							}
							break;
					}
					break;
			}
		}

		uint32_t buttons = SDL_GetMouseState(&xMouse, &yMouse);
		if (buttons & SDL_BUTTON(1)) {
			drawElement(matrix, brushSize, xMouse / 4, yMouse / 4, width, height, element);
		}

		matrix->updateMatrix();
		matrix->refreshMatrix();

		window->clear();
		window->renderMatrix(matrix, width, height);

		AssetManager* assetManager = AssetManager::getInstance();
		window->renderTexture(window->loadImage(assetManager>getElementIcon(element)), 10, 10, 2);
		window->renderTexture(window->loadText(assetManager->getElementLabel(element)), 10, 75, 1);
		window->display();

		if ((SDL_GetTicks() - time) < 10) {
			SDL_Delay(10);
		}
	}

	delete window;
	delete matrix;
	return 0;
}
