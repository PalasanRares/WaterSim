#include "utils.h"

void initializeMatrix(byte** matrix, const int width, const int height) {
	for (int i = 0; i < width; i++) {
		matrix[i] = new byte[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			matrix[i][j] = 0;
		}
	}
}

void updateMatrix(byte** matrix, const int width, const int height) {
	for (int i = 0; i < width; i++) {
		for (int j = height - 1; j >= 0; j--) {
			if (matrix[i][j] == 1) {
				bool movedDown = false;
				if (j < height - 1) {
					if (matrix[i][j + 1] == 0) {
						matrix[i][j + 1] = 1;
						matrix[i][j] = 0;
						movedDown = true;
					}
					else if (i > 0 && matrix[i - 1][j + 1] == 0) {
						matrix[i - 1][j + 1] = 1;
						matrix[i][j] = 0;
						movedDown = true;
					}
					else if (i < width - 1 && matrix[i + 1][j + 1] == 0) {
						matrix[i + 1][j + 1] = 1;
						matrix[i][j] = 0;
						movedDown = true;
					}
				}
				if (!movedDown) {
					if ((double)rand() / (double)RAND_MAX > 0.5) {
						byte speed = 4;
						while (speed > 0) {
							if (i > speed && matrix[i - speed][j] == 0) {
								matrix[i - speed][j] = 1;
								matrix[i][j] = 0;
								speed = 1;
							}	
							speed -= 1;
						}
					}
					else {
						byte speed = 4;
						while (speed > 0) {
							if (i < width - speed && matrix[i + speed][j] == 0) {
								matrix[i + speed][j] = 1;
								matrix[i][j] = 0;
								speed = 1;
							}
							speed -= 1;
						}
					}
				}
			}
		}
	}
}

void drawElement(byte** matrix, int brushSize, const int x, const int y, const int width, const int height, const byte element) {
	for (int i = x - brushSize; i < x + brushSize; i++) {
		for (int j = y - brushSize; j < y + brushSize; j++) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				if (matrix[i][j] == 0 || element == 0) {
					matrix[i][j] = element;
				}
			}
		}
	}
}

void loadTextures(RenderWindow* window, SDL_Texture** textures) {
	textures[1] = window->loadImage("res/Water.png");
	textures[2] = window->loadImage("res/Wood.png");
}