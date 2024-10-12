#include "elements/gases/Fire.hpp"
#include "Matrix.hpp"
#include "colorPicker.hpp"
#include "elements/Eraser.hpp"
#include "Iron.hpp"
#include "ElementManager.hpp"

void Fire::disappear(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 5) {
    matrix->setPosition(i, j, new Eraser());
  }
}

void Fire::setWoodOnFire(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 25) {
    if (checkTop(matrix, i, j) || checkLeft(matrix, i, j) || checkRight(matrix, i, j) || checkBottom(matrix, i, j)) {
      return;
    }
  }
}

void Fire::heatUpIron(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j - 1) && matrix->getPosition(i, j - 1)->getId() == IRON) {
    ((Iron*) matrix->getPosition(i, j - 1))->heatUp();
  }
}

bool Fire::checkTop(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i - 1, j) && matrix->getPosition(i - 1, j)->getId() == WOOD) {
    matrix->setPosition(i - 1, j, new Fire());
    return true;
  }
  return false;
}

bool Fire::checkLeft(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j - 1) && matrix->getPosition(i, j - 1)->getId() == WOOD) {
    matrix->setPosition(i, j - 1, new Fire());
    return true;
  }
  return false;
}

bool Fire::checkRight(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j + 1) && matrix->getPosition(i, j + 1)->getId() == WOOD) {
    matrix->setPosition(i, j + 1, new Fire());
    return true;
  }
  return false;
}

bool Fire::checkBottom(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i + 1, j) && matrix->getPosition(i + 1, j)->getId() == WOOD) {
    matrix->setPosition(i + 1, j, new Fire());
    return true;
  }
  return false;
}

Fire::Fire() : Gas(FIRE, GAS, pickFire()) {}

void Fire::update(Matrix* matrix, const int& i, const int& j) {
  Gas::update(matrix, i, j);
  setWoodOnFire(matrix, i, j);
  heatUpIron(matrix, i, j);
  disappear(matrix, i, j);
}
