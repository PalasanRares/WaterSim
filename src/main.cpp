#include <SDL2/SDL.h>
#include <iostream>

#include "RenderWindow.h"
#include "utils.h"

using namespace std;

int main() {
	const char* title = "WaterSim 0.1";
	const int width = 400;
	const int height = 250;
	RenderWindow* window = new RenderWindow(title, width, height);
	bool running = true;

	SDL_Event event;

	vector<vector<char>> screenMatrix;
	initializeMatrix(screenMatrix, width, height);

	while (running) {
		uint32_t time = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		window->clear();
		window->renderMatrix(screenMatrix);
		window->display();

		if ((SDL_GetTicks() - time) < 10) {
			SDL_Delay(10);
		}
	}

	delete window;
}