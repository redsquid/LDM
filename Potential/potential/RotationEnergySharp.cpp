#include "RotationEnergySharp.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

RotationEnergySharp::RotationEnergySharp(const uint vA) :
    J0(2. / 5 * Const::m0 * pow(Const::r0, 2) * pow(vA, 5. / 3))
{
}

RotationEnergySharp::~RotationEnergySharp() {
}

double RotationEnergySharp::operator() (const Shape& shape, const double vI, const double vK) const {
    return pow(Const::hbar, 2) * pow(vK, 2) / (2 * calcJpar(shape)) +
            pow(Const::hbar, 2) * (vI * (vI + 1) - pow(vK, 2)) / (2 * calcJperp(shape));
}

double RotationEnergySharp::calcJpar(const Shape& shape) const {
    const gsl_function function = {.function = jparIntegrand, .params = const_cast<Shape*>(&shape)};
    return J0 * (15. / 16) * gsl_integration_glfixed(&function, -shape.q1(), shape.q1(), GaussTable::get());
}

double RotationEnergySharp::calcJperp(const Shape& shape) const {
    const gsl_function function = {.function = jperpIntegrand, .params = const_cast<Shape*>(&shape)};
    return J0 * (15. / 32) * gsl_integration_glfixed(&function, -shape.q1(), shape.q1(), GaussTable::get());
}

double RotationEnergySharp::jparIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s(z), 4);
}

double RotationEnergySharp::jperpIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s(z), 2) * (4 * pow(z, 2) + pow(s(z), 2));
}
