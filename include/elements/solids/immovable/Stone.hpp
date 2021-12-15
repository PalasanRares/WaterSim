#ifndef _STONE_HPP_
#define _STONE_HPP_

#include "elements/solids/immovable/ImmovableSolid.hpp"

class Stone : public ImmovableSolid {
private:
  void erodate(Matrix* matrix, const int& i, const int& j);

  bool erodateTop(Matrix* matrix, const int& i, const int& j);
  bool erodateRight(Matrix* matrix, const int& i, const int& j);
  bool erodateLeft(Matrix* matrix, const int& i, const int& j);

public:
  Stone();

  void update(Matrix* matrix, const int& i, const int& j) override;

};

#endif
