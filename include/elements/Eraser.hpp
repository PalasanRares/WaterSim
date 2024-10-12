#ifndef _NONE_HPP_
#define _NONE_HPP_

#include "Element.hpp"
#include "types.hpp"

using namespace std;

class Eraser : public Element {
public:
  Eraser();

  void update(Matrix* matrix, const int& i, const int& j) const;

};

#endif
