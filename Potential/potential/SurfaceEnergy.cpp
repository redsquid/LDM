#include "SurfaceEnergy.h"
#include "Constants.h"

#include <iostream>

const size_t SurfaceEnergy::ORDER = 32;
static double calcBs(double z, void* params);

SurfaceEnergy::SurfaceEnergy(const uint A, const uint Z) :
    es0(calcEs0(A, Z)),
    GAUSS_FIXED_TABLE(gsl_integration_glfixed_table_alloc(ORDER))
{
}

SurfaceEnergy::~SurfaceEnergy() {
    gsl_integration_glfixed_table_free(GAUSS_FIXED_TABLE);
}

double SurfaceEnergy::operator ()(Shape& shape) {
    const gsl_function function = {.function = calcBs, .params = &shape};
    const double bs = 1 / 2. * gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);
    return es0 * (bs - 1);
}

double SurfaceEnergy::calcEs0(const uint A, const uint Z) {
    const double as = Constants::as;
    const double ks = Constants::ks;
    return as * pow(A, 2 / 3.) * (1 - ks * pow(A - 2 * Z, 2) / pow(A, 2));
}

static double calcBs(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return shape(z) * sqrt(1 + pow(shape.deriv(z), 2));
}

