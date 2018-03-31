#ifndef SURFACEENERGY_H
#define SURFACEENERGY_H

#include <cstdlib>
#include <gsl/gsl_integration.h>
#include "Shape.h"

class SurfaceEnergy {
public:
    SurfaceEnergy(const uint A, const uint Z);
    virtual ~SurfaceEnergy();
    double operator ()(const Shape& shape) const;
    double es0() const;
private:
    static const size_t ORDER;
    const double es0_;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
};

#endif // SURFACEENERGY_H
