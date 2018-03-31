#ifndef COULOMBENERGYSHARP_H
#define COULOMBENERGYSHARP_H

#include <cstdlib>
#include <gsl/gsl_integration.h>
#include "Shape.h"

class CoulombEnergySharp {
public:
    CoulombEnergySharp(const uint A, const uint Z);
    virtual ~CoulombEnergySharp();
    double operator ()(const Shape& shape) const;
    double ec0() const;
private:
    static const size_t ORDER;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
    const double ec0_;
};

#endif // COULOMBENERGYSHARP_H
