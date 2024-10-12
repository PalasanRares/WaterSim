#include "Glass.hpp"

#include "colorPicker.hpp"
#include "ElementManager.hpp"

Glass::Glass() : ImmovableSolid(GLASS, IMMOVABLE_SOLID, pickGlass()) {};
