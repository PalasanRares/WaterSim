#include "Matrix.hpp"
#include "elements/Eraser.hpp"
#include "elements/liquids/Water.hpp"
#include "elements/liquids/Acid.hpp"

Matrix::Matrix(const int width, const int height) : width(width), height(height) {
  matrix = new Element**[width];
  for (int i = 0; i < width; i++) {
    matrix[i] = new Element*[height];
    for (int j = 0; j < height; j++) {
      matrix[i][j] = new Eraser();
    }
  }
}

Element*** Matrix::getMatrix() {
  return matrix;
}

const int Matrix::getWidth() {
  return width;
}

const int Matrix::getHeight() {
  return height;
}

Element* Matrix::getPosition(const int& i, const int& j) {
  return matrix[i][j];
}

Element* Matrix::getPositionSafe(const int& i, const int& j) {
  return (i >= 0 && i < width && j >= 0 && j < height) ? matrix[i][j] : nullptr;
}

bool Matrix::checkPosition(const int& i, const int& j) {
  return i >= 0 && i < width && j >= 0 && j < height;
}

bool Matrix::checkAroundForElement(const int& i, const int& j, const watersim::byte& elementId) {
  Element* up = this->getPositionSafe(i - 1, j);
  Element* right = this->getPositionSafe(i, j + 1);
  Element* down = this->getPositionSafe(i + 1, j);
  Element* left = this->getPositionSafe(i, j - 1);
  return (up != nullptr && up->getId() == elementId) || 
    (right != nullptr && right->getId() == elementId) || 
    (down != nullptr && down->getId() == elementId) || 
    (left != nullptr && left->getId() == elementId);
}

void Matrix::setPosition(const int& i, const int& j, Element* element) {
  delete matrix[i][j];
  matrix[i][j] = element;
}

void Matrix::swapPosition(const int& i, const int& j, const int& ii, const int& jj) {
  Element* aux = matrix[i][j];
  matrix[i][j] = matrix[ii][jj];
  matrix[ii][jj] = aux;
}

void Matrix::updateMatrix() {
  for (int i = 0; i < width; i++) {
    for (int j = height - 1; j >= 0; j--) {
      matrix[i][j]->update(this, i, j);
    }
  }
}

void Matrix::refreshMatrix() {
  for (int i = 0; i < width; i++) {
    for (int j = height - 1; j >= 0; j--) {
      matrix[i][j]->setUpdated(false);
    }
  }
}

Matrix::~Matrix() {
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      delete matrix[i][j];
    }
    delete[] matrix[i];
  }
  delete[] matrix;
}
