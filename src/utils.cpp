#include "utils.h"

void initializeMatrix(vector<vector<char>>& matrix, const int width, const int height) {
	for (int i = 0; i < height; i++) {
		vector<char> aux(width, 0);
		matrix.push_back(aux);
	}
}