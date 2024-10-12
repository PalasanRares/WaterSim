#ifndef __ELEMENT_MANAGER_HPP__
#define __ELEMENT_MANAGER_HPP__

#include "elements/Element.hpp"

enum ElementId { 
    ERASER = 0, 
    LIQUID, 
    WATER = 1, 
    IMMOVABLE_SOLID, 
    ACID = 2, 
    MOVABLE_SOLID, 
    GAS, 
    SAND = 3, 
    WOOD = 4, 
    STONE = 5, 
    VAPOR = 6, 
    GLASS = 7,
    LAVA = 8, 
    FIRE = 9, 
    IRON = 10, 
    DIRT = 11 
};

class ElementManager {
private:
  ElementManager() {};

  static ElementManager* instance;

public:
  static ElementManager* getInstance();

  Element* createElement(const int& elementId);

};

#endif
