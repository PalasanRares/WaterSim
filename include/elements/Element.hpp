#ifndef _ELEMENT_HPP_
#define _ELEMENT_HPP_

#include "types.hpp"

using namespace std;

class Matrix;

class Element {
private:
  byte id;
  int type;
  bool updated;

public:
  Element(byte id, int type);

  virtual void update(Matrix* matrix, const int& i, const int& j) = 0;

  byte getId();
  int getType();
  bool getUpdated();

  void setUpdated(bool updated);
};

#endif
