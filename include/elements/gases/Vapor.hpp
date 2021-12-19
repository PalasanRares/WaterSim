#ifndef _VAPOR_HPP_
#define _VAPOR_HPP_

#include "elements/gases/Gas.hpp"

class Vapor : public Gas {
private:
  void condensate(Matrix* matrix, const int& i, const int& j);

public:
  Vapor();

  void update(Matrix* matrix, const int& i, const int& j) override;

};

#endif
