#include "CoulombEnergy.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

CoulombEnergy::CoulombEnergy(const uint vA, const uint vZ) :
    ecSharp(vA, vZ),
    vR0_(r0 * pow(vA, 1. / 3))
{
}

CoulombEnergy::~CoulombEnergy() {
}

double CoulombEnergy::operator ()(const Shape& shape) const {
    return ecSharp(shape) + ecSharp.ec0() * calcI1(shape);
    return calcI1(shape);
}

double CoulombEnergy::calcI1(const Shape& s) const {
    Params p(0, 0, vR0_, ecSharp.ec0(), s);
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, -s.getC(), s.getC(), GaussTable::get());
}

double CoulombEnergy::calcI2(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(z, 0, tmp.R0, tmp.EC0, tmp.SHAPE);
    const gsl_function function = {.function = calcI3, .params = &p};
    return gsl_integration_glfixed(&function, -tmp.SHAPE.getC(), tmp.SHAPE.getC(), GaussTable::get());
}

double CoulombEnergy::calcI3(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(tmp.Z1, z,  tmp.R0, tmp.EC0, tmp.SHAPE);
    const gsl_function function = {.function = integrand, .params = &p};
    return gsl_integration_glfixed(&function, 0, 2 * M_PI, GaussTable::get());
}

double CoulombEnergy::integrand(double fi, void* params) {
    const Params& p = *(static_cast<Params*>(params));
    const double z1 = p.Z1;
    const double z2 = p.Z2;
    const double vR0 = p.R0;
    const double ec0 = p.EC0;
    const Shape& s = p.SHAPE;

    const double sigma = sqrt(pow((z1 - z2), 2) + s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(fi));

    const double f = -15. * ec0 / (16 * M_PI * pow(vR0, 5) * ad) * pow(ad / sigma, 4)
            * (2 * sigma / ad - 5 + (5 + 3 * sigma / ad + pow(sigma / a, 2) / 2 ) * exp(-sigma / ad));

    return f * s(z1) * (s(z1) - s(z2) * cos(fi) - s.deriv(z1) * (z1 - z2))
            * s(z2) * (s(z2) -s(z1) * cos(fi) + s.deriv(z2) * (z1 - z2));
}

double CoulombEnergy::ec0() const {
    return ecSharp.ec0();
}
