#ifndef SURFACEENERGYSHARP_H
#define SURFACEENERGYSHARP_H

#include "Shape.h"

#include <cstdlib>

class SurfaceEnergySharp {
public:
    SurfaceEnergySharp(const uint A, const uint Z);
    virtual ~SurfaceEnergySharp();
    double operator ()(const Shape& shape) const;
    double es0() const;

private:
    static double calcIntegral(const Shape& shape);
    static double integrand(double z, void* params);

    static constexpr double as = 17.9439; //MeV
    static constexpr double ks = 1.7826;

    const double es0_;

};

#endif // SURFACEENERGYSHARP_H
