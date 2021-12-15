#ifndef _LIQUID_HPP_
#define _LIQUID_HPP_

#include "../Element.hpp"
#include "types.h"

#include <stdlib.h>

using namespace std;

class Liquid : public Element {
private:
  bool goDown(Matrix* matrix, const int& i, const int& j);
  bool goDownSide(Matrix* matrix, const int& i, const int& j);
  bool goSideways(Matrix* matrix, const int& i, const int& j);

public:
  Liquid(byte id, int color) : Element(id, color) {};

  void update(Matrix* matrix, const int& i, const int& j);

};

#endif
