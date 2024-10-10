#ifndef __DIRT_HPP__
#define __DIRT_HPP__

#include "MovableSolid.hpp"

class Dirt : public MovableSolid {
private:
    bool wet;

    bool isTouchingWater(Matrix* matrix, const int& i, const int& j);

    void ownUpdate(Matrix* matrix, const int& i, const int& j);

public:
    Dirt();

    void update(Matrix* matrix, const int& i, const int& j) override;

    bool isWet();
};

#endif
