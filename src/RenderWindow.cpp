#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) : window(nullptr), renderer(nullptr) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		cout << "Window failed to initialize. Error " << SDL_GetError() << endl;
	}
	else {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == nullptr) {
			cout << "Renderer failed to initialize. Error " << SDL_GetError() << endl;
		}
		else {
			TTF_Init();
			font = TTF_OpenFont("./fonts/pixelated.ttf", 36);
			if (font == nullptr) {
				cout << "Font failed to load. Error " << TTF_GetError() << endl;
			}
		}
	}
}

RenderWindow::~RenderWindow() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
}

void RenderWindow::clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}

void RenderWindow::renderMatrix(Matrix* matrix, const int width, const int height) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			SDL_Rect rect;
			rect.x = i * 4; rect.y = j * 4;
			rect.w = 4; rect.h = 4; //2,2 nice filter
			rgb color = matrix->getPosition(i, j)->getColor();
			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

SDL_Texture* RenderWindow::loadImage(const char* path) {
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, path);
	if (texture == nullptr) {
		cout << "Failed to load texture. Error" << SDL_GetError() << endl;
	}
	return texture;
}

void RenderWindow::renderElement(SDL_Texture* texture) {
	SDL_Rect source;
	source.x = 0; source.y = 0;
	source.w = 32; source.h = 32;
	SDL_Rect destination;
	destination.x = 10; destination.y = 10;
	destination.w = 64; destination.h = 64;
	SDL_RenderCopy(renderer, texture, &source, &destination);
}

void RenderWindow::renderText(const string text) {
	SDL_Color color = {255, 255, 255};
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
	SDL_Rect dest;
	dest.x = 10; dest.y = 75;
	textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_QueryTexture(textTexture, nullptr, nullptr, &dest.w, &dest.h);
	SDL_RenderCopy(renderer, textTexture, nullptr, &dest);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}
