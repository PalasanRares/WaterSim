#ifndef _DRAWER_HPP_
#define _DRAWER_HPP_

class Matrix;

class Drawer {
private:
  int brushSize;
  int maxBrushSize;

public:
  Drawer(const int maxBrushSize) : brushSize(1), maxBrushSize(maxBrushSize) {};

  void modifyBrushSize(const int& increment);

  void drawElement(Matrix* matrix, const int& x, const int& y, const int& element);

  const int& getBrushSize();

};

#endif
