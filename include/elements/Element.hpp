#ifndef _ELEMENT_HPP_
#define _ELEMENT_HPP_

#include "types.hpp"
#include "colorPicker.hpp"

using namespace std;

class Matrix;

class Element {
private:
  byte id;
  int type;
  bool updated;
  rgb color;

public:
  Element(byte id, int type, rgb color);

  virtual void update(Matrix* matrix, const int& i, const int& j) = 0;

  byte getId();
  int getType();
  bool getUpdated();
  rgb getColor();

  void setUpdated(bool updated);
};

#endif
