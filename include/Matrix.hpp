#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <vector>

#include "types.hpp"
#include "Element.hpp"

using namespace std;

class Matrix {
private:
  vector<vector<Element>> matrix;
  int width;
  int height;

public:
  Matrix(const int width, const int height);

  const vector<vector<Element>>& getMatrix();
  const int& getWidth();
  const int& getHeight();

  const Element& getPosition(const int& i, const int& j);
  void setPosition(const int& i, const int& j, const Element& element);

  bool checkAroundForElement(const int& i, const int& j, const int& elementId);
  void swapPosition(const int& i, const int& j, const int& ii, const int& jj);

  void updateElements();
  void refreshElements();

  ~Matrix();

};

#endif
