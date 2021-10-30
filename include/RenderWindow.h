#pragma once
#include <SDL2/SDL.h>
#include <string>
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
};