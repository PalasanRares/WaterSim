#include "Stone.hpp"

#include "Matrix.hpp"
#include "Eraser.hpp"
#include "ElementManager.hpp"

void Stone::erodate(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 1) {
    if (erodateTop(matrix, i, j) || erodateRight(matrix, i, j) || erodateLeft(matrix, i, j)) {
      return;
    }
  }
}

bool Stone::erodateTop(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j - 1) && matrix->getPosition(i, j - 1)->getId() == WATER) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i, j - 1, new Eraser());
    return true;
  }
  return false;
}

bool Stone::erodateRight(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i + 1, j) && matrix->getPosition(i + 1, j)->getId() == WATER) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i + 1, j, new Eraser());
    return true;
  }
  return false;
}

bool Stone::erodateLeft(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i - 1, j) && matrix->getPosition(i - 1, j)->getId() == WATER) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i - 1, j, new Eraser());
    return true;
  }
  return false;
}


Stone::Stone() : ImmovableSolid(STONE, IMMOVABLE_SOLID, pickStone()) {};

void Stone::update(Matrix* matrix, const int& i, const int& j) {
  ImmovableSolid::update(matrix, i, j);
  erodate(matrix, i, j);
}
