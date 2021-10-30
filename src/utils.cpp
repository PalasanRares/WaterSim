#include "utils.h"

void initializeMatrix(vector<vector<char>>& matrix, const int width, const int height) {
	for (int i = 0; i < width; i++) {
		vector<char> aux(height, 0);
		matrix.push_back(aux);
	}
}

void updateMatrix(vector<vector<char>>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = matrix.at(0).size() - 1; j >= 0; j--) {
			if (matrix.at(i).at(j) == 1) {
				bool movedDown = false;
				if (j < matrix.at(0).size() - 1) {
					if (matrix.at(i).at(j + 1) == 0) {
						matrix.at(i).at(j + 1) = 1;
						matrix.at(i).at(j) = 0;
						movedDown = true;
					}
					else if (i > 0 && matrix.at(i - 1).at(j + 1) == 0) {
						matrix.at(i - 1).at(j + 1) = 1;
						matrix.at(i).at(j) = 0;
						movedDown = true;
					}
					else if (i < matrix.size() - 1 && matrix.at(i + 1).at(j + 1) == 0) {
						matrix.at(i + 1).at(j + 1) = 1;
						matrix.at(i).at(j) = 0;
						movedDown = true;
					}
				}
				if (!movedDown) {
					if ((double)rand() / (double)RAND_MAX > 0.5) {
						if (i > 0 && matrix.at(i - 1).at(j) == 0) {
							matrix.at(i - 1).at(j) = 1;
							matrix.at(i).at(j) = 0;
						}	
					}
					else if (i < matrix.size() - 1 && matrix.at(i + 1).at(j) == 0) {
							matrix.at(i + 1).at(j) = 1;
							matrix.at(i).at(j) = 0;
					}
				}
			}
		}
	}
}

void drawWater(vector<vector<char>>& matrix, int brushSize, int x, int y) {
	for (int i = x - brushSize; i < x + brushSize; i++) {
		for (int j = y - brushSize; j < y + brushSize; j++) {
			if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix.at(0).size()) {
				matrix.at(i).at(j) = 1;
			}
		}
	}
}