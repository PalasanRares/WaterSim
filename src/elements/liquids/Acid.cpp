#include "Acid.hpp"

#include "Eraser.hpp"
#include "Matrix.hpp"
#include "ElementManager.hpp"

void Acid::dissolve(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 20) {
    if (dissolveBottom(matrix, i, j) || dissolveLeft(matrix, i, j) || dissolveRight(matrix, i, j) || dissolveTop(matrix, i, j)) {
      return;
    }
  }
}

bool Acid::dissolveTop(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j - 1) && matrix->getPosition(i, j - 1)->getId() != ERASER && matrix->getPosition(i, j - 1)->getId() != ACID) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i, j - 1, new Eraser());
    return true;
  }
  return false;
}

bool Acid::dissolveLeft(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i - 1, j) && matrix->getPosition(i - 1, j)->getId() != ERASER && matrix->getPosition(i - 1, j)->getId() != ACID) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i - 1, j, new Eraser());
    return true;
  }
  return false;
}

bool Acid::dissolveRight(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i + 1, j) && matrix->getPosition(i + 1, j)->getId() != ERASER && matrix->getPosition(i + 1, j)->getId() != ACID) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i + 1, j, new Eraser());
    return true;
  }
  return false;
}

bool Acid::dissolveBottom(Matrix* matrix, const int& i, const int& j) {
  if (matrix->checkPosition(i, j + 1) && matrix->getPosition(i, j + 1)->getId() != ERASER && matrix->getPosition(i, j + 1)->getId() != ACID) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i, j + 1, new Eraser());
    return true;
  }
  return false;
}

Acid::Acid() : Liquid(ACID, LIQUID, pickAcid()) {};

void Acid::update(Matrix* matrix, const int& i, const int& j) {
  Liquid::update(matrix, i, j);
  dissolve(matrix, i, j);

}
