#include "Vapor.hpp"

#include "colorPicker.hpp"
#include "Matrix.hpp"
#include "Water.hpp"
#include "ElementManager.hpp"

void Vapor::condensate(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 10000 < 1) {
    matrix->setPosition(i, j, new Water());
  }
}

Vapor::Vapor() : Gas(VAPOR, GAS, pickVapor()) {};

void Vapor::update(Matrix* matrix, const int& i, const int& j) {
  Gas::update(matrix, i, j);
  condensate(matrix, i, j);
}
