#include "Dirt.hpp"

#include "Matrix.hpp"
#include "ElementManager.hpp"

Dirt::Dirt() : MovableSolid(DIRT, MOVABLE_SOLID, pickDirt()), wet(false) {}

bool Dirt::isTouchingWater(Matrix* matrix, const int& i, const int& j) {
    if (matrix->checkAroundForElement(i, j, WATER)) {
        this->wet = true;
        this->setColor(pickWetDirt());
    }
}

void Dirt::ownUpdate(Matrix* matrix, const int& i, const int& j) {
    if (!getUpdated()) {
        if (goDown(matrix, i, j)) {
            setUpdated(true);
        }
    }
}

void Dirt::update(Matrix* matrix, const int& i, const int& j) {
    if (!this->wet) {
        MovableSolid::update(matrix, i, j);
        this->isTouchingWater(matrix, i, j);
    } else {
        this->ownUpdate(matrix, i, j);
    }
}

bool Dirt::isWet() {
    return this->wet;
}
