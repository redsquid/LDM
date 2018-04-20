#include "SurfaceEnergy.h"

#include "const/Const.h"
#include "const/GaussTable.h"


#include <gsl/gsl_integration.h>

#include <iostream>
SurfaceEnergy::SurfaceEnergy(const uint vA, const uint vZ) :
    essharp(vA, vZ),
    vR0_(r0 * pow(vA, 1. / 3)),
    cs_(as * (1 - ks * pow((vA - 2. * vZ) / vA, 2))),
    es0_(cs_ * pow(vA, 2. / 3)),
    en0_((1 - 3 * pow(a / vR0_, 2) + (vR0_ / a + 1)
                     * (2 + 3 * a / vR0_ + 3 * pow(a / vR0_, 2)) * exp(-2 * vR0_ / a)))
{
}

SurfaceEnergy::~SurfaceEnergy() {
}

double SurfaceEnergy::operator ()(const Shape& shape) const {

    return  (1 / (4 * M_PI) * calcI1(shape) - en0_) * es0_;
}

double SurfaceEnergy::calcI1(const Shape& s) const {
    Params p(0, 0, cs_, vR0_, s);
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, -s.zmax(), s.zmax(), GaussTable::get());
}

double SurfaceEnergy::calcI2(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(z, 0, tmp.CS, tmp.R0, tmp.SHAPE);
    const gsl_function function = {.function = calcI3, .params = &p};
    return gsl_integration_glfixed(&function, -tmp.SHAPE.zmax(), tmp.SHAPE.zmax(), GaussTable::get());
}

double SurfaceEnergy::calcI3(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(tmp.Z1, z, tmp.CS, tmp.R0, tmp.SHAPE);
    const gsl_function function = {.function = integrand, .params = &p};
    return gsl_integration_glfixed(&function, 0, 2 * M_PI, GaussTable::get());
}

double SurfaceEnergy::integrand(double fi, void* params) {
    const Params& p = *(static_cast<Params*>(params));
    const double z1 = p.Z1;
    const double z2 = p.Z2;
    const double cs = p.CS;
    const double R0 = p.R0;
    const Shape& s = p.SHAPE;


    double sigma = sqrt(s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(fi) + pow(z1 - z2, 2));

    double funn = (2 - (2 + 2. * sigma * R0 / a + pow(sigma * R0 / a, 2)) * exp(-sigma * R0 / a))
        / pow(sigma, 4);

    return funn * s(z1) * (s(z1) - s(z2) * cos(fi) - s.deriv(z1) * (z1 - z2))
            * s(z2) * (s(z2) - s(z1) * cos(fi) - s.deriv(z2) * (z2 - z1));
}

double SurfaceEnergy::en0() const {
    return en0_;
}
