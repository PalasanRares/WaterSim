#include "elements/Element.hpp"

Element::Element(byte id, int type) : id(id), type(type), updated(false) {};

byte Element::getId() {
  return id;
}

int Element::getType() {
  return type;
}

bool Element::getUpdated() {
  return updated;
}

void Element::setUpdated(bool updated) {
  this->updated = updated;
}
