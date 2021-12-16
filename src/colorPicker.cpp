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

rgb pickStone() {
  int random = rand() % 24;
  return rgb(random + 105, random + 105, random + 105);
}

rgb pickVapor() {
  int random = rand() % 10;
  return rgb(random + 211, random + 211, random + 211);
}

rgb pickGlass() {
  return rgb(rand() % 27 + 170, 251, 255);
}
