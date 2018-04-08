#include "SurfaceEnergySharp.h"

#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

SurfaceEnergySharp::SurfaceEnergySharp(const uint A, const uint Z) :
    es0_(as * pow(A, 2. / 3) * (1 - ks * pow((A - 2. * Z) / A, 2)))
{
}

SurfaceEnergySharp::~SurfaceEnergySharp() {
}

double SurfaceEnergySharp::operator ()(const Shape& shape) const {
    return 1. / 2 * calcIntegral(shape) * es0_;
}

double SurfaceEnergySharp::calcIntegral(const Shape& shape) {
    const gsl_function function = {.function = integrand, .params = const_cast<Shape*>(&shape)};
    return gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GaussTable::get());
}

double SurfaceEnergySharp::integrand(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return shape(z) * sqrt(1 + pow(shape.deriv(z), 2));
}

double SurfaceEnergySharp::es0() const {
    return es0_;
}
