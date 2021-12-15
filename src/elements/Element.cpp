#include "elements/Element.hpp"

Element::Element(byte id, int type, rgb color) : id(id), type(type), color(color), updated(false) {};

byte Element::getId() {
  return id;
}

int Element::getType() {
  return type;
}

bool Element::getUpdated() {
  return updated;
}

rgb Element::getColor() {
  return color;
}

void Element::setUpdated(bool updated) {
  this->updated = updated;
}
