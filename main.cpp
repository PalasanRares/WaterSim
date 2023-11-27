#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <iostream>

#include "RenderWindow.hpp"
#include "Water.hpp"
#include "Eraser.hpp"
#include "Element.hpp"
#include "Liquid.hpp"
#include "Acid.hpp"
#include "Matrix.hpp"
#include "types.hpp"
#include "AssetManager.hpp"
#include "Drawer.hpp"

using namespace std;

int main(int argc, char** argv) {
	const char* title = "WaterSim 0.10";
	const int width = 250;
	const int height = 125;
	byte element = 1;
	byte elementNr = 10;
	RenderWindow* window = new RenderWindow(title, width * 4, height * 4);
	bool running = true;

	SDL_HideCursor();

	Matrix* matrix = new Matrix(width, height);
	Drawer* drawer = new Drawer(3);

	SDL_Event event;

	float xMouse, yMouse;

	int brushSize = drawer->getBrushSize();

	AssetManager* assetManager = AssetManager::getInstance();

	while (running) {
		uint32_t time = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					running = false;
					break;
				case SDL_EVENT_KEY_DOWN:
					switch (event.key.keysym.sym) {
						case SDLK_RIGHT:
							drawer->modifyBrushSize(1);
							brushSize = drawer->getBrushSize();
							break;
						case SDLK_LEFT:
							drawer->modifyBrushSize(-1);
							brushSize = drawer->getBrushSize();
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

		Uint32 buttons = SDL_GetMouseState(&xMouse, &yMouse);
		if (buttons & SDL_BUTTON(1)) {
			drawer->drawElement(matrix, xMouse / 4, yMouse / 4, element);
		}

		int cursorOffsetX = xMouse - (brushSize + 3) * 3;
		int cursorOffsetY = yMouse - (brushSize + 3) * 3;

		matrix->updateMatrix();
		matrix->refreshMatrix();

		window->clear();
		window->renderMatrix(matrix, width, height);

		SDL_Texture* elementIcon = window->loadImage(assetManager->getElementIcon(element));
		SDL_Texture* elementLabel = window->loadText(assetManager->getElementLabel(element));
		SDL_Texture* cursor = window->loadImage(assetManager->getCursor(brushSize));
		window->renderTexture(elementIcon, 10, 10, 2);
		window->renderTexture(elementLabel, 10, 75, 1);
		window->renderTexture(cursor, cursorOffsetX, cursorOffsetY, 4);
		SDL_DestroyTexture(elementIcon);
		SDL_DestroyTexture(elementLabel);
		SDL_DestroyTexture(cursor);

		window->display();

		if ((SDL_GetTicks() - time) < 10) {
			SDL_Delay(10);
		}
	}

	delete window;
	delete matrix;
	return 0;
}
