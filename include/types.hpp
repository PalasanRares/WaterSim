#pragma once

namespace watersim {

  typedef unsigned char byte;

}

enum ElementId { ERASER = 0, LIQUID, WATER = 1, IMMOVABLE_SOLID, ACID = 2, MOVABLE_SOLID, GAS, SAND = 3, WOOD = 4 , STONE = 5, VAPOR = 6, GLASS = 7,
                LAVA = 8, FIRE = 9, IRON = 10, DIRT = 11 };

struct rgb {
  rgb(int r, int g, int b) : r(r), g(g), b(b) {};
  int r;
  int g;
  int b;

};
