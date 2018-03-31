#ifndef ROTATIONENERGY_H
#define ROTATIONENERGY_H

#include <cstdlib>
#include "Shape.h"
#include <gsl/gsl_integration.h>

class RotationEnergy {
public:
    RotationEnergy(const uint vA);
    virtual ~RotationEnergy();
    double operator() (const Shape& shape, const double vI, const double vK) const;

private:
    double getJpar(const Shape& shape) const;
    double getJperp(const Shape& shape) const;

    static const size_t ORDER;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
    const double J0;

};

#endif // ROTATIONENERGY_H
