#ifndef ROTATIONENERGY_H
#define ROTATIONENERGY_H

#include "Shape.h"

#include <cstdlib>

class RotationEnergy {
public:
    RotationEnergy(const uint vA);
    virtual ~RotationEnergy();
    double operator() (const Shape& shape, const double vI, const double vK) const;

private:
    double calcJpar(const Shape& shape) const;
    double calcJperp(const Shape& shape) const;
    static double jparIntegrand(double z, void* params);
    static double jperpIntegrand(double z, void* params);

    static constexpr double r0 = 1.2249; //fm
    static constexpr double am = 0.704; // fm  [29]

    const double J0;
    const double mass;

};

#endif // ROTATIONENERGY_H
