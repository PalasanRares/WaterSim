#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "utils.h"
#include "types.h"

using namespace std;

int main() {
	const char* title = "WaterSim 0.4";
	const int width = 500;
	const int height = 250;
	int brushSize = 2;
	byte element = 1; //0 - eraser, 1 - water, 2 - wood
	byte elementNr = 3;
	RenderWindow* window = new RenderWindow(title, width * 2, height * 2);
	bool running = true;

	SDL_Texture** textures = new SDL_Texture*[3];
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
							if (brushSize < 6) {
								brushSize += 2;
							}
							break;
						case SDLK_LEFT:
							if (brushSize > 2) {
								brushSize -= 2;
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
			drawElement(screenMatrix, brushSize, xMouse / 2, yMouse / 2, width, height, element);
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
	SDL_DestroyTexture(textures[0]);
	SDL_DestroyTexture(textures[1]);
	delete[] textures;
}