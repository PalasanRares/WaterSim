#include "factories/ElementFactory.hpp"

#include "elements/Eraser.hpp"
#include "elements/liquids/Water.hpp"
#include "elements/liquids/Acid.hpp"
#include "elements/liquids/Lava.hpp"
#include "elements/solids/movable/Sand.hpp"
#include "elements/solids/immovable/Wood.hpp"
#include "elements/solids/immovable/Stone.hpp"
#include "elements/solids/immovable/Glass.hpp"
#include "elements/gases/Vapor.hpp"
#include "elements/gases/Fire.hpp"

ElementFactory* ElementFactory::instance = nullptr;

ElementFactory* ElementFactory::getInstance() {
  if (instance == nullptr) {
    instance = new ElementFactory();
  }
  return instance;
}

Element* ElementFactory::createElement(const int& elementId) {
  switch (elementId) {
    case ERASER:
      return new Eraser();
      break;
    case WATER:
      return new Water();
      break;
    case ACID:
      return new Acid();
      break;
    case SAND:
      return new Sand();
      break;
    case WOOD:
      return new Wood();
      break;
    case STONE:
      return new Stone();
      break;
    case VAPOR:
      return new Vapor();
      break;
    case GLASS:
      return new Glass();
      break;
    case LAVA:
      return new Lava();
      break;
    case FIRE:
      return new Fire();
      break;
  }
  return nullptr;
}
