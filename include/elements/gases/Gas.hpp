#ifndef _GAS_HPP_
#define _GAS_HPP_

#include "elements/Element.hpp"

class Gas : public Element {
private:
  bool goUp(Matrix* matrix, const int& i, const int& j);
  bool goUpSide(Matrix* matrix, const int& i, const int& j);
  bool goSideways(Matrix* matrix, const int& i, const int& j);

public:
  Gas(byte id, int type, rgb color) : Element(id, type, color) {};

  void update(Matrix* matrix, const int& i, const int& j);

};

#endif
