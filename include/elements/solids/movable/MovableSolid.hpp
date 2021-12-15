#ifndef _MOVABLE_SOLID_HPP
#define _MOVABLE_SOLID_HPP

#include "elements/Element.hpp"
#include "types.hpp"

class MovableSolid : public Element {
private:
  bool goDown(Matrix* matrix, const int& i, const int& j);
  bool goDownSide(Matrix* matrix, const int& i, const int& j);

public:
  MovableSolid(byte id, int type) : Element(id, type) {};

  void update(Matrix* matrix, const int& i, const int& j);

};

#endif
