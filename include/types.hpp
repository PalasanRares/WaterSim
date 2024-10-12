#pragma once

namespace watersim {

  typedef unsigned char byte;

}

struct rgb {
  rgb(int r, int g, int b) : r(r), g(g), b(b) {};
  int r;
  int g;
  int b;

};
