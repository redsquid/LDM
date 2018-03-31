#include "SurfaceEnergySharp.h"
#include "const/Const.h"

#include <iostream>

const size_t SurfaceEnergySharp::ORDER = 32;
static double calcBs(double z, void* params);

SurfaceEnergySharp::SurfaceEnergySharp(const uint A, const uint Z) :
    es0_(Const::as * pow(A, 2 / 3.) * (1 - Const::ks * pow(A - 2 * Z, 2) / pow(A, 2))),
    GAUSS_FIXED_TABLE(gsl_integration_glfixed_table_alloc(ORDER))
{
}

SurfaceEnergySharp::~SurfaceEnergySharp() {
    gsl_integration_glfixed_table_free(GAUSS_FIXED_TABLE);
}

double SurfaceEnergySharp::operator ()(const Shape& shape) const {
    const gsl_function function = {.function = calcBs, .params = const_cast<Shape*>(&shape)};
    return es0_* 1 / 2. * gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);
}

double SurfaceEnergySharp::es0() const {
    return es0_;
}

static double calcBs(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return shape(z) * sqrt(1 + pow(shape.deriv(z), 2));
}

