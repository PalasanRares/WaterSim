#ifndef _ELEMENT_FACTORY_HPP_
#define _ELEMENT_FACTORY_HPP_

#include "elements/Element.hpp"

class ElementFactory {
private:
  ElementFactory() {};

  static ElementFactory* instance;

public:
  static ElementFactory* getInstance();

  Element* createElement(const int& elementId);

};

#endif
