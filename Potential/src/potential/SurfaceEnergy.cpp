#include "SurfaceEnergy.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

struct Params {
    double ro1;
    double ro2;
    double ro1pow2;
    double ro2pow2;
    double drodz1;
    double drodz2;
    double z1;
    double deltaz;
    double R0;
    Shape* shape;
};

SurfaceEnergy::SurfaceEnergy(const uint vA, const uint vZ) :
    essharp(vA, vZ),
    vR0_(r0 * pow(vA, 1. / 3)),
    es0_(as * (1 - ks * pow((vA - 2. * vZ) / vA, 2)) * pow(vA, 2. / 3)),
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
    Shape shape(s);
    Params p;
    p.R0 = vR0_;
    p.shape = &shape;
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, s.zmin(), s.zmax(), GaussTable::get());
}

double SurfaceEnergy::calcI2(double z, void* params) {
    Params* p = static_cast<Params*>(params);
    p->z1 = z;
    p->ro1 = p->shape->value(z);
    p->ro1pow2 = p->shape->pow2(z);
    p->drodz1 = p->shape->deriv(z);
    const gsl_function function = {.function = calcI3, .params = p};
    return gsl_integration_glfixed(&function, p->shape->zmin(), p->shape->zmax(), GaussTable::get());
}

double SurfaceEnergy::calcI3(double z, void* params) {
    Params* p = static_cast<Params*>(params);
    p->deltaz = z - p->z1;
    p->ro2 = p->shape->value(z);
    p->ro2pow2 = p->shape->pow2(z);
    p->drodz2 = p->shape->deriv(z);
    const gsl_function function = {.function = integrand, .params = p};
    return gsl_integration_glfixed(&function, 0, 2 * M_PI, GaussTable::get());
}

double SurfaceEnergy::integrand(double fi, void* params) {
    const Params* p = static_cast<Params*>(params);
    const double ro1 = p->ro1;
    const double ro2 = p->ro2;
    const double ro1pow2 = p->ro1pow2;
    const double ro2pow2 = p->ro2pow2;
    const double drodz1 = p->drodz1;
    const double drodz2 = p->drodz2;
    const double deltaz = p->deltaz;
    const double R0 = p->R0;

    double sigma = sqrt(ro1pow2 + ro2pow2 - 2 * ro1 * ro2 * cos(fi) + pow(deltaz, 2));

    double funn = (2 - (2 + 2. * sigma * R0 / a + pow(sigma * R0 / a, 2)) * exp(-sigma * R0 / a))
        / pow(sigma, 4);

    return funn * ro1 * (ro1 - ro2 * cos(fi) + drodz1 * (deltaz))
            * ro2 * (ro2 - ro1 * cos(fi) - drodz2 * (deltaz));
}
