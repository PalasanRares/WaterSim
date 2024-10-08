#ifndef _IMMOVABLE_SOLID_HPP_
#define _IMMOVABLE_SOLID_HPP_

#include "elements/Element.hpp"
#include "types.hpp"

#include <stdlib.h>

using namespace std;

class ImmovableSolid : public Element {
public:
  ImmovableSolid(watersim::byte id, int type, rgb color) : Element(id, type, color) {};

  void update(Matrix* matrix, const int& i, const int& j);

};

#endif
