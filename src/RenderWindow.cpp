#include "RenderWindow.hpp"

#include <algorithm>

#include "ElementManager.hpp"
#include "Iron.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) : window(nullptr), renderer(nullptr) {
	window = SDL_CreateWindow(title, width, height, 0);
	if (window == nullptr) {
		cout << "Window failed to initialize. Error " << SDL_GetError() << endl;
	}
	else {
		renderer = SDL_CreateRenderer(window, nullptr);
		if (renderer == nullptr) {
			cout << "Renderer failed to initialize. Error " << SDL_GetError() << endl;
		}
		else {
			TTF_Init();
			font = TTF_OpenFont("./fonts/pixelated.ttf", 36);
			if (font == nullptr) {
				cout << "Font failed to load. Error " << SDL_GetError() << endl;
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
			SDL_FRect rect;
			rect.x = i * 4; rect.y = j * 4;
			rect.w = 4; rect.h = 4; //2,2 nice filter
			Element* element = matrix->getPosition(i, j);
			rgb color = element->getColor();
			if (element->getId() == IRON) {
				color.r = min(255.f, color.r + (255 * ((Iron*) element)->getHeatLevel()));
				color.g = max(0.f, color.g - (255 * ((Iron*) element)->getHeatLevel()));
				color.b = max(0.f, color.b - (255 * ((Iron*) element)->getHeatLevel()));
			}
			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

SDL_Texture* RenderWindow::loadImage(const string& path) {
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer, path.c_str());
	return texture;
}

SDL_Texture* RenderWindow::loadText(const string& text) {
	SDL_Texture* texture = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Color color = {255, 255, 255};

	surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_DestroySurface(surface);

	return texture;
}

void RenderWindow::renderTexture(SDL_Texture* texture, const int& x, const int& y, const int& multiplier) {
	SDL_FRect destination;
	destination.x = x;
	destination.y = y;

	float textureWidth, textureHeight;

	SDL_GetTextureSize(texture, &textureWidth, &textureHeight);

	destination.w = multiplier * textureWidth;
	destination.h = multiplier * textureHeight;
	SDL_RenderTexture(renderer, texture, nullptr, &destination);
	SDL_DestroyTexture(texture);
}
