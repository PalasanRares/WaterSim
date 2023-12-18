#ifndef _FIRE_HPP_
#define _FIRE_HPP_

#include "elements/gases/Gas.hpp"

class Fire : public Gas {
private:
  void disappear(Matrix* matrix, const int& i, const int& j);

  void setWoodOnFire(Matrix* matrix, const int& i, const int& j);
  void heatUpIron(Matrix* matrix, const int& i, const int& j);

  bool checkTop(Matrix* matrix, const int& i, const int& j);
  bool checkLeft(Matrix* matrix, const int& i, const int& j);
  bool checkRight(Matrix* matrix, const int& i, const int& j);
  bool checkBottom(Matrix* matrix, const int& i, const int& j);

public:
  Fire();

  void update(Matrix* matrix, const int& i, const int& j) override;

};

#endif
