#ifndef POTENTIAL_H
#define POTENTIAL_H

#include "Shape.h"

#include "SurfaceEnergy.h"
#include "CoulombEnergy.h"
#include "RotationEnergy.h"

class Potential {
public:
    Potential(const uint vA, const uint vZ);
    virtual ~Potential();
    double operator() (const Shape& shape, const double vL, const double vK) const;

private:
    const SurfaceEnergy se;
    const CoulombEnergy ce;
    const RotationEnergy re;
};

#endif // POTENTIALSHARP_H
