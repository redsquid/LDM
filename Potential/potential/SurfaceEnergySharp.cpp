#include "SurfaceEnergySharp.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

SurfaceEnergySharp::SurfaceEnergySharp(const uint A, const uint Z) :
    es0_(Const::as * pow(A, 2 / 3.) * (1 - Const::ks * pow(A - 2 * Z, 2) / pow(A, 2)))
{
}

SurfaceEnergySharp::~SurfaceEnergySharp() {
}

double SurfaceEnergySharp::operator ()(const Shape& shape) const {
    return es0_* 1 / 2. * calcIntegral(shape);
}


double SurfaceEnergySharp::calcIntegral(const Shape& shape) {
    const gsl_function function = {.function = integrand, .params = const_cast<Shape*>(&shape)};
    return gsl_integration_glfixed(&function, -shape.q1(), shape.q1(), GaussTable::get());
}

double SurfaceEnergySharp::integrand(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return shape(z) * sqrt(1 + pow(shape.deriv(z), 2));
}

double SurfaceEnergySharp::es0() const {
    return es0_;
}
