#include "elements/liquids/Liquid.hpp"
#include "Matrix.hpp"

bool Liquid::goDown(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j + 1) && matrix->getPosition(i, j + 1)->getId() == ERASER) {
      matrix->swapPosition(i, j, i, j + 1);
      return true;
  }
  return false;
}

bool Liquid::goDownSide(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 50) {
    if (matrix->checkPosition(i + 1, j + 1) && matrix->getPosition(i + 1, j + 1)->getId() == ERASER) {
      matrix->swapPosition(i, j, i + 1, j + 1);
      return true;
    }
  }
  else {
    if (matrix->checkPosition(i - 1, j + 1) && matrix->getPosition(i - 1, j + 1)->getId() == ERASER) {
      matrix->swapPosition(i, j, i - 1, j + 1);
      return true;
    }
  }
  return false;
}

bool Liquid::goSideways(Matrix* matrix, const int& i, const int& j) {
  watersim::byte speed = 1;
  if (rand() % 100 < 50) {
    while (speed < 5 && matrix->checkPosition(i - speed, j) && matrix->getPosition(i - speed, j)->getId() == ERASER) {
      speed += 1;
    }
    if (speed - 1 > 0) {
      matrix->swapPosition(i, j, i - speed + 1, j);
      return true;
    }
  }
  else {
    while (speed < 5 && matrix->checkPosition(i + speed, j) && matrix->getPosition(i + speed, j)->getId() == ERASER) {
      speed += 1;
    }
    if (speed - 1 > 0) {
      matrix->swapPosition(i, j, i + speed - 1, j);
      return true;
    }
  }
  return false;
}

void Liquid::update(Matrix* matrix, const int& i, const int& j) {
  if (!getUpdated()) {
    if (goDown(matrix, i, j)) {
      setUpdated(true);
      return;
    }
    if (goDownSide(matrix, i, j)) {
      setUpdated(true);
      return;
    }
    if (goSideways(matrix, i, j)) {
      setUpdated(true);
      return;
    }
  }
}
