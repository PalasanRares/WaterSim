#include "colorPicker.hpp"

rgb pickWater() {
  return rgb(0, 0, rand() % 56 + 200);
}

rgb pickSand() {
  return rgb(194, 178, rand() % 56 + 48);
}

rgb pickWood() {
  int random = rand() % 6;
  return rgb(random + 54, random + 38, random);
}

rgb pickAcid() {
  return rgb(0, rand() % 56 + 200, 0);
}