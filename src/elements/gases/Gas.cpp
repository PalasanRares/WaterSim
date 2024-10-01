#include "elements/gases/Gas.hpp"
#include "Matrix.hpp"

bool Gas::goUp(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j - 1) && (matrix->getPosition(i, j - 1)->getId() == ERASER || matrix->getPosition(i, j - 1)->getType() == LIQUID)) {
    matrix->swapPosition(i, j, i, j - 1);
    return true;
  }
  return false;
}

bool Gas::goUpSide(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 50) {
    if (matrix->checkPosition(i - 1, j - 1) && (matrix->getPosition(i - 1, j - 1)->getId() == ERASER || matrix->getPosition(i - 1, j - 1)->getType() == LIQUID)) {
      matrix->swapPosition(i, j, i - 1, j - 1);
      return true;
    }
  }
  else if (matrix->checkPosition(i + 1, j - 1) && (matrix->getPosition(i + 1, j - 1)->getId() == ERASER || matrix->getPosition(i + 1, j - 1)->getType() == LIQUID)) {
    matrix->swapPosition(i, j, i + 1, j - 1);
    return true;
  }
  return false;
}

bool Gas::goSideways(Matrix* matrix, const int& i, const int& j) {
  watersim::byte speed = 1;
  if (rand() % 100 < 50) {
    while (speed < 10 && matrix->checkPosition(i - speed, j) && matrix->getPosition(i - speed, j)->getId() == ERASER) {
      speed += 1;
    }
    if (speed - 1 > 0) {
      matrix->swapPosition(i, j, i - speed + 1, j);
      return true;
    }
  }
  else {
    while (speed < 10 && matrix->checkPosition(i + speed, j) && matrix->getPosition(i + speed, j)->getId() == ERASER) {
      speed += 1;
    }
    if (speed - 1 > 0) {
      matrix->swapPosition(i, j, i + speed - 1, j);
      return true;
    }
  }
  return false;
}

void Gas::update(Matrix* matrix, const int& i, const int& j) {
  if (!getUpdated()) {
    if (goUp(matrix, i ,j) || goUpSide(matrix, i, j) || goSideways(matrix, i, j)) {
      setUpdated(true);
      return;
    }
  }
}
