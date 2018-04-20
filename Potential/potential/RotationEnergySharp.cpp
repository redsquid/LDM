#include "RotationEnergySharp.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

#include <iostream>
RotationEnergySharp::RotationEnergySharp(const uint vA) :
    J0(2. / 5 * m0 * pow(r0, 2) * pow(vA, 5. / 3)),
    er0(0.5 * Const::hpl * Const::hpl / J0)
    //mass(m0 * vA)
{

}

RotationEnergySharp::~RotationEnergySharp() {
}

double RotationEnergySharp::operator() (const Shape& shape, const int vL, const int vK) const {

    const double jpar = calcJpar(shape);
    const double jperp = calcJperp(shape) - 2.5 * pow(shape.zcm(), 2);

    double bj_ldm = 1. / jperp;
    double bk_ldm = (jperp - jpar) * bj_ldm / jpar;
    return er0 * vL * vL * bj_ldm + er0 * bk_ldm * vK * vK;
}

double RotationEnergySharp::calcJpar(const Shape& shape) const {
    const gsl_function function = {.function = jparIntegrand, .params = const_cast<Shape*>(&shape)};
    return (15. / 16) * gsl_integration_glfixed(&function, -shape.zmax(), shape.zmax(), GaussTable::get());
}

double RotationEnergySharp::calcJperp(const Shape& shape) const {
    const gsl_function function = {.function = jperpIntegrand, .params = const_cast<Shape*>(&shape)};
    return (15. / 32) * gsl_integration_glfixed(&function, -shape.zmax(), shape.zmax(), GaussTable::get());
}

double RotationEnergySharp::jparIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s(z), 4);
}

double RotationEnergySharp::jperpIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s(z), 2) * (4 * pow(z, 2) + pow(s(z), 2));
}
