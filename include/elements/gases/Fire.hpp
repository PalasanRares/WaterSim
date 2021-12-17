#ifndef _FIRE_HPP_
#define _FIRE_HPP_

#include "elements/gases/Gas.hpp"

class Fire : public Gas {
private:
  void disappear(Matrix* matrix, const int& i, const int& j);

public:
  Fire();

  void update(Matrix* matrix, const int& i, const int& j) override;

};

#endif
