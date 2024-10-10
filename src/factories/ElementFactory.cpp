#include "factories/ElementFactory.hpp"

#include "Eraser.hpp"
#include "Water.hpp"
#include "Acid.hpp"
#include "Lava.hpp"
#include "Sand.hpp"
#include "Wood.hpp"
#include "Stone.hpp"
#include "Glass.hpp"
#include "Vapor.hpp"
#include "Fire.hpp"
#include "Iron.hpp"
#include "Dirt.hpp"

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
    case IRON:
      return new Iron();
      break;
    case DIRT:
      return new Dirt();
      break;
  }
  return nullptr;
}
