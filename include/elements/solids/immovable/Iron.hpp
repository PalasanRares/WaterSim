#ifndef _IRON_HPP_
#define _IRON_HPP_

#include "ImmovableSolid.hpp"

class Iron : public ImmovableSolid {
private:
    float heatLevel;

    void heatUpOtherIronUp(Matrix* matrix, const int& i, const int& j);
    void heatUpOtherIronRight(Matrix* matrix, const int& i, const int& j);
    void heatUpOtherIronDown(Matrix* matrix, const int& i, const int& j);
    void heatUpOtherIronLeft(Matrix* matrix, const int& i, const int& j);

    void heatUpOtherIron(Iron* otherIron);

public:
    Iron();

    float getHeatLevel();
    void setHeatLevel(float level);

    void heatUpOtherIron(Matrix* matrix, const int& i, const int& j);

    void update(Matrix* matrix, const int& i, const int& j) override;

    void heatUp();
    void coolDown();
};

#endif