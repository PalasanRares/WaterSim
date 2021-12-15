#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include "types.hpp"
#include <iostream>
#include "elements/Element.hpp"

using namespace std;

class Matrix {
private:
  Element*** matrix;
  int width;
  int height;

public:
  Matrix(const int width, const int height);

  Element*** getMatrix();
  const int getWidth();
  const int getHeight();

  Element* getPosition(const int& i, const int& j);
  bool checkPosition(const int& i, const int& j);
  void setPosition(const int& i, const int& j, Element* element);
  void swapPosition(const int& i, const int& j, const int& ii, const int& jj);
  void updateMatrix();
  void refreshMatrix();

  ~Matrix();

};

#endif
