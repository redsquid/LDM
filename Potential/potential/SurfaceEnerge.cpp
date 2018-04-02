#include "SurfaceEnerge.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

SurfaceEnerge::SurfaceEnerge(const uint vA, const uint vZ , const double vEs0Sharp) :
    vR0_(r0 * pow(vA, 1. / 3)),
    cs_(as * (1 - ks * pow(vA - 2 * vZ, 2) / pow(vA, 2))),
    e0_(vEs0Sharp * (1 - 3 * pow(a / vR0_, 2) + (vR0_ / a + 1)
                     * (2 + 3 * a / vR0_ + 3 * pow(a / vR0_, 2)) * exp(-2 * vR0_ / a)))
{
}

SurfaceEnerge::~SurfaceEnerge() {
}

double SurfaceEnerge::operator ()(const Shape& shape) const {
    return calcI1(shape);
}

double SurfaceEnerge::calcI1(const Shape& s) const {
    Params p(0, 0, cs_, s);
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, -s.q1(), s.q1(), GaussTable::get());
}

double SurfaceEnerge::calcI2(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(z, 0, tmp.CS, tmp.SHAPE);
    const gsl_function function = {.function = calcI3, .params = &p};
    return gsl_integration_glfixed(&function, -tmp.SHAPE.q1(), tmp.SHAPE.q1(), GaussTable::get());
}

double SurfaceEnerge::calcI3(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(tmp.Z1, z, tmp.CS, tmp.SHAPE);
    const gsl_function function = {.function = integrand, .params = &p};
    return gsl_integration_glfixed(&function, 0, 2 * M_PI, GaussTable::get());
}

double SurfaceEnerge::integrand(double fi, void* params) {
    const Params& p = *(static_cast<Params*>(params));
    const double z1 = p.Z1;
    const double z2 = p.Z2;
    const double cs = p.CS;
    const Shape& s = p.SHAPE;

    const double sigma = sqrt(pow((z1 - z2), 2) + s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(fi));

    const double f = -cs / (4 * M_PI * pow(r0, 2) * pow(sigma, 4))
            * (2 - (2 + 2 * sigma / a + pow(sigma / a, 2)) * exp(-sigma / a));

    return f * s(z1) * (s(z1) - s(z2) * cos(fi) - s.deriv(z1) * (z1 - z2))
            * s(z2) * (s(z2) -s(z1) * cos(fi) + s.deriv(z2) * (z1 - z2));
}

double SurfaceEnerge::e0() const {
    return e0_;
}
