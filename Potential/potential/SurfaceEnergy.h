#ifndef SURFACEENERGY_H
#define SURFACEENERGY_H

#include <cstdlib>
#include <gsl/gsl_integration.h>
#include "Shape.h"

class SurfaceEnergy {
public:
    SurfaceEnergy(const uint A, const uint Z);
    virtual ~SurfaceEnergy();
    double operator ()(Shape& shape);

private:
    static const size_t ORDER;
    static double calcEs0(const uint A, const uint Z);
    const double es0;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
};

#endif // SURFACEENERGY_H
