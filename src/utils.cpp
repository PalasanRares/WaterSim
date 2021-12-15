#include "utils.hpp"

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
					if (matrix[i][j + 1] == 0 || matrix[i][j + 1] == 4) {
						matrix[i][j + 1] = 1;
						matrix[i][j] = 0;
						movedDown = true;
					}
					else if (i > 0 && (matrix[i - 1][j + 1] == 0 || matrix[i - 1][j + 1] == 4)) {
						matrix[i - 1][j + 1] = 1;
						matrix[i][j] = 0;
						movedDown = true;
					}
					else if (i < width - 1 && (matrix[i + 1][j + 1] == 0 || matrix[i + 1][j + 1] == 4)) {
						matrix[i + 1][j + 1] = 1;
						matrix[i][j] = 0;
						movedDown = true;
					}
				}
				if (!movedDown) {
					if ((double)rand() / (double)RAND_MAX > 0.5) {
						byte speed = 1;
						while (speed < 5 && i > speed && matrix[i - speed][j] == 0) {
							speed += 1;
						}
						speed -= 1;
						if (speed > 0) {
							matrix[i - speed][j] = 1;
							matrix[i][j] = 0;
						}
					}
					else {
						byte speed = 1;
						while (speed < 5 && i + speed < width && matrix[i + speed][j] == 0) {
							speed += 1;
						}
						speed -= 1;
						if (speed > 0) {
							matrix[i + speed][j] = 1;
							matrix[i][j] = 0;
						}
					}
				}
			}
			else if (matrix[i][j] == 3) {
				if (j < height - 1) {
					if (matrix[i][j + 1] <= 1 || matrix[i][j + 1] == 4) {
						swap(matrix, i, j, i, j + 1);
					}
					else if ((double)rand() / (double)RAND_MAX >  0.5) {
						if (i > 0 && matrix[i - 1][j + 1] <= 0) {
							swap(matrix, i, j, i - 1, j + 1);
						}
					}
					else if (i < width - 1 && matrix[i + 1][j + 1] <= 0) {
						swap(matrix, i, j, i + 1, j + 1);
					}
				}
			}
			else if (matrix[i][j] == 4) {
				double random = (double)rand() / (double)RAND_MAX;
				bool movedDown = false;
				if (j < height - 1) {
					if (matrix[i][j + 1] == 0) {
						matrix[i][j + 1] = 4;
						matrix[i][j] = 0;
						movedDown = true;
					}
					else if (i > 0 && matrix[i - 1][j + 1] == 0) {
						matrix[i - 1][j + 1] = 4;
						matrix[i][j] = 0;
						movedDown = true;
					}
					else if (i < width - 1 && matrix[i + 1][j + 1] == 0) {
						matrix[i + 1][j + 1] = 4;
						matrix[i][j] = 0;
						movedDown = true;
					}
				}
				if (!movedDown) {
					if (random > 0.5) {
						byte speed = 4;
						while (speed > 0) {
							if (i > speed && matrix[i - speed][j] == 0) {
								matrix[i - speed][j] = 4;
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
								matrix[i + speed][j] = 4;
								matrix[i][j] = 0;
								speed = 1;
							}
							speed -= 1;
						}
					}
				}
				if (j < height - 1 && random < 0.03) {
					if (matrix[i][j + 1] != 0 && matrix[i][j + 1] != 4) {
						matrix[i][j] = 0;
						matrix[i][j + 1] = 0;
					}
					else if (i > 0 && matrix[i - 1][j + 1] != 0 && matrix[i - 1][j + 1] != 4) {
						matrix[i][j] = 0;
						matrix[i - 1][j + 1] = 0;
					}
					else if (i < width - 1 && matrix[i + 1][j + 1] != 0 && matrix[i + 1][j + 1] != 4) {
						matrix[i][j] = 0;
						matrix[i + 1][j + 1] = 0;
					}
				}
			}
		}
	}
}

void drawElement(Matrix* matrix, int brushSize, const int x, const int y, const int width, const int height, byte element) {
	for (int i = x - brushSize; i < x + brushSize; i++) {
		for (int j = y - brushSize; j < y + brushSize; j++) {
			if (i >= 0 && i < width && j >= 0 && j < height) {
				Element* elem;
				switch (element) {
			    case 0:
			      elem = new Eraser();
			      break;
			    case 1:
			      elem = new Water();
			      break;
			    case 2:
			      elem = new Acid();
			      break;
			  }
				if (matrix->getPosition(i, j)->getId() == ERASER || elem->getId() == ERASER) {
					matrix->setPosition(i, j, elem);
				}
			}
		}
	}
}

void loadTextures(RenderWindow* window, SDL_Texture** textures) {
	textures[1] = window->loadImage("./res/Water.png");
	textures[2] = window->loadImage("./res/Acid.png");
	textures[3] = window->loadImage("./res/Sand.png");
	textures[4] = window->loadImage("./res/Wood.png");
}

void swap(byte** matrix, const int i, const int j, const int x, const int y) {
	byte aux = matrix[i][j];
	matrix[i][j] = matrix[x][y];
	matrix[x][y] = aux;
}
