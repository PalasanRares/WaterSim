#include "elements/gases/Fire.hpp"
#include "Matrix.hpp"
#include "colorPicker.hpp"
#include "elements/Eraser.hpp"

void Fire::disappear(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 5) {
    matrix->setPosition(i, j, new Eraser());
  }
}

Fire::Fire() : Gas(FIRE, GAS, pickFire()) {}

void Fire::update(Matrix* matrix, const int& i, const int& j) {
  Gas::update(matrix, i, j);
  disappear(matrix, i, j);
}
