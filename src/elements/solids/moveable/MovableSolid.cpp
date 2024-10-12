#include "MovableSolid.hpp"

#include "Matrix.hpp"
#include "ElementManager.hpp"

bool MovableSolid::goDown(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j + 1) && (matrix->getPosition(i, j + 1)->getId() == ERASER || matrix->getPosition(i, j + 1)->getType() == LIQUID)) {
      matrix->swapPosition(i, j, i, j + 1);
      return true;
  }
  return false;
}

bool MovableSolid::goDownSide(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 50) {
    if (matrix->checkPosition(i + 1, j + 1) && (matrix->getPosition(i + 1, j + 1)->getId() == ERASER || matrix->getPosition(i + 1, j + 1)->getType() == LIQUID)) {
      matrix->swapPosition(i, j, i + 1, j + 1);
      return true;
    }
  }
  else {
    if (matrix->checkPosition(i - 1, j + 1) && (matrix->getPosition(i - 1, j + 1)->getId() == ERASER || matrix->getPosition(i - 1, j + 1)->getType() == LIQUID)) {
      matrix->swapPosition(i, j, i - 1, j + 1);
      return true;
    }
  }
  return false;
}

void MovableSolid::update(Matrix* matrix, const int& i, const int& j) {
  if (!getUpdated()) {
    if (goDown(matrix, i, j) || goDownSide(matrix, i, j)) {
      setUpdated(true);
      return;
    }
  }
}
