#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* title, int width, int height) : window(nullptr), renderer(nullptr) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		cout << "Window failed to initialize. Error" << SDL_GetError() << endl;
	} 
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			cout << "Renderer failed to initialize. Error" << SDL_GetError() << endl;
		}
	}
}

RenderWindow::~RenderWindow() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void RenderWindow::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}

void RenderWindow::renderMatrix(byte** matrix, const int width, const int height) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (matrix[i][j] != 0) {
				SDL_RenderDrawPoint(renderer, i, j);
			}
		}
	}
}