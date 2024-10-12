#include "elements/Element.hpp"

Element::Element(int id, int type, rgb color) : id(id), type(type), color(color), updated(false) {};

int Element::getId() const {
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

void Element::setColor(rgb color) {
  this->color = color;
}

void Element::setUpdated(bool updated) const {
  this->updated = updated;
}
