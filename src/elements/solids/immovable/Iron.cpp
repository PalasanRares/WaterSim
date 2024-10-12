#include "Iron.hpp"

#include "Matrix.hpp"
#include "ElementManager.hpp"

void Iron::heatUpOtherIronUp(Matrix* matrix, const int& i, const int& j) {
    if (matrix->checkPosition(i, j - 1) && matrix->getPosition(i, j - 1)->getId() == IRON) {
        heatUpOtherIron((Iron*) matrix->getPosition(i, j - 1));
    }
}

void Iron::heatUpOtherIronRight(Matrix* matrix, const int& i, const int& j) {
    if (matrix->checkPosition(i + 1, j) && matrix->getPosition(i + 1, j)->getId() == IRON) {
        heatUpOtherIron((Iron*) matrix->getPosition(i + 1, j));
    }
}

void Iron::heatUpOtherIronDown(Matrix* matrix, const int& i, const int& j) {
    if (matrix->checkPosition(i, j + 1) && matrix->getPosition(i, j + 1)->getId() == IRON) {
        heatUpOtherIron((Iron*) matrix->getPosition(i, j + 1));
    }
}

void Iron::heatUpOtherIronLeft(Matrix* matrix, const int& i, const int& j) {
    if (matrix->checkPosition(i - 1, j) && matrix->getPosition(i - 1, j)->getId() == IRON) {
        heatUpOtherIron((Iron*) matrix->getPosition(i - 1, j));
    }
}

void Iron::heatUpOtherIron(Iron* otherIron) {
    if (heatLevel > 0.f && !getUpdated()) {
        float otherHeatLevel = otherIron->getHeatLevel();
        float averageHeatLevel = (heatLevel + otherHeatLevel) / 2;
        heatLevel = averageHeatLevel;
        otherIron->setHeatLevel(averageHeatLevel);
    }
}

Iron::Iron() : ImmovableSolid(IRON, IMMOVABLE_SOLID, pickIron()), heatLevel(0.f) {};

float Iron::getHeatLevel() {
    return heatLevel;
}

void Iron::setHeatLevel(float level) {
    if (!getUpdated()) {
        heatLevel = level;
        setUpdated(true);
    }
}

void Iron::heatUpOtherIron(Matrix* matrix, const int& i, const int& j) {
    heatUpOtherIronUp(matrix, i, j);
    heatUpOtherIronRight(matrix, i, j);
    heatUpOtherIronDown(matrix, i, j);
    heatUpOtherIronLeft(matrix, i, j);
}

void Iron::update(Matrix* matrix, const int& i, const int& j) {
    ImmovableSolid::update(matrix, i, j);
    heatUpOtherIron(matrix, i, j);
    coolDown();
}

void Iron::heatUp() {
    if (!getUpdated()) {
        if (heatLevel < 1.f) {
            heatLevel += 0.01f;
        } else {
            heatLevel = 1.f;
        }
        setUpdated(true);
    }
}

void Iron::coolDown() {
    if (!getUpdated()) {
        if (heatLevel > 0.f) {
            heatLevel -= 0.0125f;
        } else {
            heatLevel = 0.f;
        }
        setUpdated(true);
    }
}
