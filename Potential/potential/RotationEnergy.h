#ifndef ROTATIONENERGY_H
#define ROTATIONENERGY_H

#include "Shape.h"

class RotationEnergy
{
public:
    RotationEnergy();
    double operator() (Shape shape, double vI, double vK);
};

#endif // ROTATIONENERGY_H
