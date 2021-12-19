#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "types.hpp"
#include "Matrix.hpp"

using namespace std;

class RenderWindow {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;

public:
	RenderWindow(const char* title, int width, int height);
	~RenderWindow();

	void clear();
	void display();
	void renderMatrix(Matrix* matrix, const int width, const int height);

	SDL_Texture* loadImage(const string& path);
	SDL_Texture* loadText(const string& text);

	void renderTexture(SDL_Texture* texture, const int& x, const int& y, const int& multiplier);
};
