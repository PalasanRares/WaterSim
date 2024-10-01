#ifndef _LIQUID_HPP_
#define _LIQUID_HPP_

#include "elements/Element.hpp"
#include "types.hpp"

#include <stdlib.h>

using namespace std;

class Liquid : public Element {
private:
  bool goDown(Matrix* matrix, const int& i, const int& j);
  bool goDownSide(Matrix* matrix, const int& i, const int& j);
  bool goSideways(Matrix* matrix, const int& i, const int& j);

public:
  Liquid(watersim::byte id, int type, rgb color) : Element(id, type, color) {};

  void update(Matrix* matrix, const int& i, const int& j);

};

#endif
