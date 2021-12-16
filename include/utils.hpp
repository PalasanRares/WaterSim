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
#include "elements/solids/movable/Sand.hpp"
#include "elements/solids/immovable/Wood.hpp"
#include "elements/solids/immovable/Stone.hpp"
#include "elements/gases/Vapor.hpp"

using namespace std;

void drawElement(Matrix* matrix, int brushSize, const int x, const int y, const int width, const int height, byte element);

void loadTextures(RenderWindow* window, SDL_Texture** textures);
