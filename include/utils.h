#pragma once
#include <vector>
#include <iostream>

using namespace std;

void initializeMatrix(vector<vector<char>>& matrix, const int width, const int height);

void updateMatrix(vector<vector<char>>& matrix);

void drawWater(vector<vector<char>>& matrix, int brushSize, int x, int y);