#pragma once
#include <iostream>

#include "types.h"

using namespace std;

void initializeMatrix(byte** matrix, const int width, const int height);

void updateMatrix(byte** matrix, const int width, const int height);

void drawWater(byte** matrix, int brushSize, const int x, const int y, const int width, const int height);