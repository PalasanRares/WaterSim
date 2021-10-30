#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.h"
#include "RenderWindow.h"

using namespace std;

void initializeMatrix(byte** matrix, const int width, const int height);

void updateMatrix(byte** matrix, const int width, const int height);

void drawElement(byte** matrix, int brushSize, const int x, const int y, const int width, const int height, const byte element);

void loadTextures(RenderWindow* window, SDL_Texture** textures);