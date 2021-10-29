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
				if (j < matrix.at(0).size() - 1 && matrix.at(i).at(j + 1) == 0) {
					matrix.at(i).at(j + 1) = 1;
					matrix.at(i).at(j) = 0;
				}
			}
		}
	}
}