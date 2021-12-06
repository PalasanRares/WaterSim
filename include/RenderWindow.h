#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

#include "types.h"

using namespace std;

class RenderWindow {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	RenderWindow(const char* title, int width, int height);
	~RenderWindow();

	void clear();
	void display();
	void renderMatrix(byte** matrix, const int width, const int height);
	SDL_Texture* loadImage(const char* path);
	void renderElement(SDL_Texture* texture);
};
