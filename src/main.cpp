#include <SDL2/SDL.h>
#include <iostream>

#include "RenderWindow.h"
#include "utils.h"

using namespace std;

int main() {
	const char* title = "WaterSim 0.1";
	const int width = 1000;
	const int height = 500;
	RenderWindow* window = new RenderWindow(title, width, height);
	bool running = true;

	SDL_Event event;

	vector<vector<char>> screenMatrix;
	initializeMatrix(screenMatrix, width, height);

	int xMouse, yMouse;

	while (running) {
		uint32_t time = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_MOUSEMOTION:
					uint32_t buttons = SDL_GetMouseState(&xMouse, &yMouse);
					if (buttons & SDL_BUTTON(1)) {
						screenMatrix.at(xMouse).at(yMouse) = 1;
					}
					break;
			}
		}

		window->clear();
		window->renderMatrix(screenMatrix);
		window->display();

		updateMatrix(screenMatrix);

		if ((SDL_GetTicks() - time) < 10) {
			SDL_Delay(10);
		}
	}

	delete window;
}