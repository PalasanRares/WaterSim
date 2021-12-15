#ifndef _ACID_HPP_
#define _ACID_HPP_

#include "Liquid.hpp"
#include "types.hpp"

using namespace std;

class Acid : public Liquid {
private:
  void dissolve(Matrix* matrix, const int& i, const int& j);

  bool dissolveTop(Matrix* matrix, const int& i, const int& j);
  bool dissolveLeft(Matrix* matrix, const int& i, const int& j);
  bool dissolveRight(Matrix* matrix, const int& i, const int& j);
  bool dissolveBottom(Matrix* matrix, const int& i, const int& j);

public:
  Acid();

  void update(Matrix* matrix, const int& i, const int& j) override;

};

#endif
