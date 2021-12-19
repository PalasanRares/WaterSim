#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

#include "types.hpp"
#include "RenderWindow.hpp"
#include "Matrix.hpp"

using namespace std;

void drawElement(Matrix* matrix, int brushSize, const int x, const int y, const int width, const int height, byte element);
