#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

#include "types.hpp"
#include "RenderWindow.hpp"
#include "Matrix.hpp"
#include "elements/Element.hpp"
#include "elements/Eraser.hpp"
#include "elements/liquids/Water.hpp"
#include "elements/liquids/Acid.hpp"

using namespace std;

void initializeMatrix(byte** matrix, const int width, const int height);

void updateMatrix(byte** matrix, const int width, const int height);

void drawElement(Matrix* matrix, int brushSize, const int x, const int y, const int width, const int height, byte element);

void loadTextures(RenderWindow* window, SDL_Texture** textures);

void swap(byte** matrix, const int i, const int j, const int x, const int y);
