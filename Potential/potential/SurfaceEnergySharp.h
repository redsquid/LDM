#ifndef SURFACEENERGYSHARP_H
#define SURFACEENERGYSHARP_H

#include <cstdlib>
#include <gsl/gsl_integration.h>
#include "Shape.h"

class SurfaceEnergySharp {
public:
    SurfaceEnergySharp(const uint A, const uint Z);
    virtual ~SurfaceEnergySharp();
    double operator ()(const Shape& shape) const;
    double es0() const;
private:
    static const size_t ORDER;
    const double es0_;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
};

#endif // SURFACEENERGYSHARP_H
