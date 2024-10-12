#include "Matrix.hpp"

#include "Eraser.hpp"

Matrix::Matrix(const int width, const int height) : width(width), height(height) {
  matrix = vector<vector<Element>>(width);
  for (int i = 0; i < width; i++) {
    matrix.at(i) = vector<Element>(height);
    for (int j = 0; j < height; j++) {
      matrix.at(i).at(j) = Eraser();
    }
  }
}

const vector<vector<Element>>& Matrix::getMatrix() {
  return matrix;
}

const int& Matrix::getWidth() {
  return width;
}

const int& Matrix::getHeight() {
  return height;
}

const Element& Matrix::getPosition(const int& i, const int& j) {
  return matrix.at(i).at(j);
}

bool Matrix::checkAroundForElement(const int& i, const int& j, const int& elementId) {
  try {
    const Element& up = matrix.at(i - 1).at(j);
    if (up.getId() == elementId) return true;
  } catch (out_of_range exception) {
    /* no-op */
  }

  try {
    const Element& right = matrix.at(i).at(j + 1);
    if (right.getId() == elementId) return true;
  } catch (out_of_range exception) {
    /* no-op */
  }

  try {
    const Element& down = matrix.at(i + 1).at(j);
		if (down.getId() == elementId) return true;
  } catch (out_of_range exception) {
		/* no-op */
  }

	try {
		const Element& left = matrix.at(i).at(j - 1);
		if (left.getId() == elementId) return true;
	} catch (out_of_range exception) {
		/* no-op */
	}

	return false;
}

void Matrix::setPosition(const int& i, const int& j, const Element& element) {
  try {
		matrix.at(i).at(j) = element;
	} catch (out_of_range exception) {
		/* no-op */
	}
}

void Matrix::swapPosition(const int& i, const int& j, const int& ii, const int& jj) {
	try {
		const Element& aux = matrix.at(i).at(j);
		matrix.at(i).at(j) = matrix.at(ii).at(jj);
		matrix.at(ii).at(jj) = aux;
	} catch (out_of_range exception) {
		/* no-op */
	}
}

void Matrix::updateElements() {
  for (int i = 0; i < width; i++) {
    for (int j = height - 1; j >= 0; j--) {
      getPosition(i, j).update(this, i, j);
    }
  }
}

void Matrix::refreshElements() {
  for (int i = 0; i < width; i++) {
    for (int j = height - 1; j >= 0; j--) {
      getPosition(i, j).setUpdated(false);
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
