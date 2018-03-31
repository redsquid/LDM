#ifndef ROTATIONENERGYSHARP_H
#define ROTATIONENERGYSHARP_H

#include <cstdlib>
#include "Shape.h"
#include <gsl/gsl_integration.h>

class RotationEnergySharp {
public:
    RotationEnergySharp(const uint vA);
    virtual ~RotationEnergySharp();
    double operator() (const Shape& shape, const double vI, const double vK) const;

private:
    double getJpar(const Shape& shape) const;
    double getJperp(const Shape& shape) const;

    static const size_t ORDER;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
    const double J0;

};

#endif // ROTATIONENERGYSHARP_H
