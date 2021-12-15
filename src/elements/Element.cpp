#include "elements/Element.hpp"

Element::Element(byte id, int color) : id(id), color(color), updated(false) {};

byte Element::getId() {
  return id;
}

int Element::getColor() {
  return color;
}

bool Element::getUpdated() {
  return updated;
}

void Element::setUpdated(bool updated) {
  this->updated = updated;
}
