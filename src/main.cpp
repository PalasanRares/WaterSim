#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

#include "RenderWindow.h"
#include "utils.h"
#include "types.h"

using namespace std;

int main(int argc, char** argv) {
	const char* title = "WaterSim 0.4";
	const int width = 250;
	const int height = 125;
	int brushSize = 1;
	byte element = 1; //0 - eraser, 1 - water, 2 - wood, 3 - sand, 4 - acid
	byte elementNr = 5;
	RenderWindow* window = new RenderWindow(title, width * 4, height * 4);
	bool running = true;

	SDL_Texture** textures = new SDL_Texture*[elementNr];
	loadTextures(window, textures);

	SDL_Event event;

	byte** screenMatrix = new byte*[width];
	initializeMatrix(screenMatrix, width, height);

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
			drawElement(screenMatrix, brushSize, xMouse / 4, yMouse / 4, width, height, element);
		}

		window->clear();
		window->renderMatrix(screenMatrix, width, height);
		window->renderElement(textures[element]);
		window->display();

		updateMatrix(screenMatrix, width, height);

		if ((SDL_GetTicks() - time) < 10) {
			SDL_Delay(10);
		}
	}

	delete window;
	for (int i = 0; i < width; i++) {
		delete[] screenMatrix[i];
	}
	delete[] screenMatrix;
	for (int i = 1; i < elementNr; i++) {
		SDL_DestroyTexture(textures[i]);
	}
	delete[] textures;
	return 0;
}
