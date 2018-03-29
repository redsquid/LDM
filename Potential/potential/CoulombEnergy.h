#ifndef COULOMBENERGY_H
#define COULOMBENERGY_H

#include <cstdlib>
#include <gsl/gsl_integration.h>
#include "Shape.h"

class CoulombEnergy {
public:
    CoulombEnergy(const uint A, const uint Z);
    virtual ~CoulombEnergy();
    double operator ()(Shape& shape);
    double ec0();
private:
    static const size_t ORDER;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;
    const double ec0_;
};

#endif // COULOMBENERGY_H
