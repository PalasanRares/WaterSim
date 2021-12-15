#ifndef _ELEMENT_HPP_
#define _ELEMENT_HPP_

#include "types.hpp"

using namespace std;

class Matrix;

class Element {
private:
  byte id;
  int color;
  bool updated;

public:
  Element(byte id, int color);

  virtual void update(Matrix* matrix, const int& i, const int& j) = 0;

  byte getId();
  int getColor();
  bool getUpdated();

  void setUpdated(bool updated);
};

#endif
