#include "simulation.h"

void simulate(byte** matrix, const int& width, const int& height) {
  for (int i = width - 1; i >= 0; i--) {
    for (int j = height - 1; j >= 0; j--) {
      switch (matrix[i][j]) {
        case 1:
          simulateWater(matrix, width, height, i, j);
          break;
        case 2:
          simulateAcid(matrix, width, height, i, j);
          break;
        case 3:
          simulateSand(matrix, width, height, i, j);
          break;
        case 4:
          simulateWood(matrix, width, height, i, j);
          break;
      }
    }
  }
}

void simulateWater(byte** matrix, const int& width, const int& height, const byte& x, const byte& y) {
  bool movedDown = false;
  int random = rand() % 100;
  if (y < height - 1) {
    if (matrix[x][y + 1] == 0) {
      matrix[x][y + 1] = 1;
      matrix[x][y] = 0;
      movedDown = true;
    }
    else if (random < 50 && x + 1 < width && matrix[x + 1][y + 1] == 0) {
      matrix[x + 1][y + 1] = 1;
      matrix[x][y] = 0;
      movedDown = true;
    }
    else if (x > 0 && matrix[x - 1][y + 1] == 0) {
      matrix[x - 1][y + 1] = 1;
      matrix[x][y] = 0;
      movedDown = true;
    }
  }
  if (!movedDown) {
    byte speed = 1;
    if (random < 50) {
      while (speed < 5 && x > speed && matrix[x - speed][y] == 0) {
        speed += 1;
      }
      if (speed - 1 > 0) {
        matrix[x - speed + 1][y] = 1;
        matrix[x][y] = 0;
      }
    }
    else {
      while (speed < 5 && x + speed < width && matrix[x + speed][y] == 0) {
        speed += 1;
      }
      if (speed - 1 > 0) {
        matrix[x + speed - 1][y] = 1;
        matrix[x][y] = 0;
      }
    }
  }
}

void simulateWood(byte** matrix, const int& width, const int& height, const byte& x, const byte& y) {
  return;
}

void simulateSand(byte** matrix, const int& width, const int& height, const byte& x, const byte& y) {
  int random = rand() % 100;
  if (y < height - 1) {
    if (matrix[x][y + 1] <= 2) {
      swap(matrix, x, y, x, y + 1);
    }
    else if (random < 50 && x < width - 1 && matrix[x + 1][y + 1] <= 2) {
      swap(matrix, x, y, x + 1, y + 1);
    }
    else if (x > 0 && matrix[x - 1][y + 1] <= 2) {
      swap(matrix, x, y, x - 1, y + 1);
    }
  }
}

void simulateAcid(byte** matrix, const int& width, const int& height, const byte& x, const byte& y) {
  return;
}
