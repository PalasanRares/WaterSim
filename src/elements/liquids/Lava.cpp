#include "Lava.hpp"

#include "Matrix.hpp"
#include "Vapor.hpp"
#include "Glass.hpp"
#include "Stone.hpp"
#include "Eraser.hpp"
#include "ElementManager.hpp"

void Lava::meltStone(Matrix* matrix, const int& i, const int& j) {
  if (rand() % 100 < 10) {
    if (checkTop(matrix, i, j, STONE)) {
      matrix->setPosition(i, j - 1, new Lava());
    }
    if (checkLeft(matrix, i, j, STONE)) {
      matrix->setPosition(i - 1, j, new Lava());
    }
    if (checkRight(matrix, i, j, STONE)) {
      matrix->setPosition(i + 1, j, new Lava());
    }
    if (checkBottom(matrix, i, j, STONE)) {
      matrix->setPosition(i, j + 1, new Lava());
    }
  }
}

void Lava::evaporateWater(Matrix* matrix, const int& i, const int& j) {
  if (checkTop(matrix, i, j, WATER)) {
    matrix->setPosition(i, j, new Stone());
    matrix->setPosition(i, j - 1, new Vapor());
  }
  else if (checkLeft(matrix, i, j, WATER)) {
    matrix->setPosition(i, j, new Stone());
    matrix->setPosition(i - 1, j, new Vapor());
  }
  else if (checkRight(matrix, i, j, WATER)) {
    matrix->setPosition(i, j, new Stone());
    matrix->setPosition(i + 1, j, new Vapor());
  }
  else if (checkBottom(matrix, i, j, WATER)) {
    matrix->setPosition(i, j, new Stone());
    matrix->setPosition(i, j + 1, new Vapor());
  }
}

void Lava::turnSandIntoGlass(Matrix* matrix, const int& i, const int& j) {
  if (checkTop(matrix, i, j, SAND)) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i, j - 1, new Glass());
  }
  if (checkLeft(matrix, i, j, SAND)) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i - 1, j, new Glass());
  }
  if (checkRight(matrix, i, j, SAND)) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i + 1, j, new Glass());
  }
  if (checkBottom(matrix, i, j, SAND)) {
    matrix->setPosition(i, j, new Eraser());
    matrix->setPosition(i, j + 1, new Glass());
  }
}

bool Lava::checkTop(Matrix* matrix, const int& i, const int& j, int element) {
  if (matrix->checkPosition(i, j - 1) && matrix->getPosition(i, j - 1)->getId() == element) {
    return true;
  }
  return false;
}

bool Lava::checkLeft(Matrix* matrix, const int& i, const int& j, int element) {
  if (matrix->checkPosition(i - 1, j) && matrix->getPosition(i - 1, j)->getId() == element) {
    return true;
  }
  return false;
}

bool Lava::checkRight(Matrix* matrix, const int& i, const int& j, int element) {
  if (matrix->checkPosition(i + 1, j) && matrix->getPosition(i + 1, j)->getId() == element) {
    return true;
  }
  return false;
}

bool Lava::checkBottom(Matrix* matrix, const int& i, const int& j, int element) {
  if (matrix->checkPosition(i, j + 1) && matrix->getPosition(i, j + 1)->getId() == element) {
    return true;
  }
  return false;
}

Lava::Lava() : Liquid(LAVA, LIQUID, pickLava()) {};

void Lava::update(Matrix* matrix, const int& i, const int& j) {
  Liquid::update(matrix, i, j);
  meltStone(matrix, i, j);
  evaporateWater(matrix, i, j);
  turnSandIntoGlass(matrix, i, j);
}
