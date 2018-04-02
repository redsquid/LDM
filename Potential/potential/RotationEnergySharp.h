#ifndef ROTATIONENERGYSHARP_H
#define ROTATIONENERGYSHARP_H

#include "Shape.h"

#include <cstdlib>

class RotationEnergySharp {
public:
    RotationEnergySharp(const uint vA);
    virtual ~RotationEnergySharp();
    double operator() (const Shape& shape, const double vI, const double vK) const;

private:
    double calcJpar(const Shape& shape) const;
    double calcJperp(const Shape& shape) const;
    static double jparIntegrand(double z, void* params);
    static double jperpIntegrand(double z, void* params);
    const double J0;
};

#endif // ROTATIONENERGYSHARP_H
