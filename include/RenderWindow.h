#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <iostream>

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
	void renderMatrix(vector<vector<char>>& matrix);
};