#ifndef _ELEMENT_HPP_
#define _ELEMENT_HPP_

#include "types.hpp"
#include "colorPicker.hpp"

using namespace std;

class Matrix;

class Element {
private:
  int id;
  int type;
  bool updated;
  rgb color;

public:
  Element(int id, int type, rgb color);

  virtual void update(Matrix* matrix, const int& i, const int& j) const = 0;

  int getId() const;
  int getType() const;
  bool getUpdated() const;

  rgb getColor() const;
  void setColor(rgb color);

  void setUpdated(bool updated);
};

#endif
