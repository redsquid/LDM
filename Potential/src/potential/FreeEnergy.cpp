#include "FreeEnergy.h"

#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

FreeEnergy::FreeEnergy(const uint vA, const uint vZ, const double vT) :
    potential(vA, vZ),
    sesharp(vA, vZ),
    vA_(vA),
    vTpow2_(pow(vT, 2))
{
}

FreeEnergy::~FreeEnergy() {

}

double FreeEnergy::operator ()(const Shape& shape, const double vL, const double vK) const {

    const double a = av * vA_ + as * pow(vA_, 2. / 3) * calcBs(shape);
    return potential(shape, vL, vK) - a * vTpow2_ + 37.81955 - 2.39799;


}

double FreeEnergy::calcBs(const Shape& shape) {
    const gsl_function function = {.function = integrand, .params = const_cast<Shape*>(&shape)};
    return 1. / 2 * gsl_integration_glfixed(&function, shape.zmin(), shape.zmax(), GaussTable::get());
}

double FreeEnergy::integrand(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return shape(z) * sqrt(1 + pow(shape.deriv(z), 2));
}
