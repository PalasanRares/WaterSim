#ifndef _LAVA_HPP_
#define _LAVA_HPP_

#include "elements/liquids/Liquid.hpp"

class Lava : public Liquid {
private:
  void meltStone(Matrix* matrix, const int& i, const int& j);
  void evaporateWater(Matrix* matrix, const int& i, const int& j);
  void turnSandIntoGlass(Matrix* matrix, const int& i, const int& j);

  bool checkTop(Matrix* matrix, const int& i, const int& j, int elemet);
  bool checkLeft(Matrix* matrix, const int& i, const int& j, int element);
  bool checkRight(Matrix* matrix, const int& i, const int& j, int element);
  bool checkBottom(Matrix* matrix, const int& i, const int& j, int element);

public:
  Lava();

  void update(Matrix* matrix, const int& i, const int& j) override;

};

#endif
