#include "CoulombEnergy.h"

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
    double dro2dz1;
    double dro2dz2;
    double z1;
    double deltaz;
    double R0;
    double ec0;
    Shape* shape;
};

CoulombEnergy::CoulombEnergy(const uint vA, const uint vZ) :
    vR0_(r0 * pow(vA, 1. / 3)),
    ec0_(pac * pow(vZ, 2) / pow(vA, 1. / 3)),
    dec_(1 - 5. / pow(vR0_ / ac, 2) * (1 - 15. / (8 * vR0_ / ac) + 21. / (8 * pow(vR0_ / ac, 3))
         - 0.75 * (1 + 9./ (2 * vR0_ / ac) + 7. / pow(vR0_ / ac, 2) + 7. / (2. * pow(vR0_ / ac, 3)))
         * exp(-2. * vR0_ / ac)))
{
}

CoulombEnergy::~CoulombEnergy() {
}

double CoulombEnergy::operator ()(const Shape& shape) const {
    return (calcI1(shape) - dec_) * ec0_;
}

double CoulombEnergy::calcI1(const Shape& s) const {
    Shape shape(s);
    Params p;
    p.R0 = vR0_;
    p.ec0 = ec0_;
    p.shape = &shape;
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, s.zmin(), s.zmax(), GaussTable::get());
}

double CoulombEnergy::calcI2(double z, void* params) {
    Params* p = static_cast<Params*>(params);
    p->z1 = z;
    p->ro1 = p->shape->value(z);
    p->ro1pow2 = p->shape->pow2(z);
    p->drodz1 = p->shape->deriv(z);
    p->dro2dz1 = 2 * p->ro1 * p->drodz1;
    const gsl_function function = {.function = calcI3, .params = p};
    return gsl_integration_glfixed(&function, p->shape->zmin(), p->shape->zmax(), GaussTable::get());
}

double CoulombEnergy::calcI3(double z, void* params) {
    Params* p = static_cast<Params*>(params);
    p->deltaz = z - p->z1;
    p->ro2 = p->shape->value(z);
    p->ro2pow2 = p->shape->pow2(z);
    p->drodz2 = p->shape->deriv(z);
    p->dro2dz2 = 2 * p->ro2 * p->drodz2;

    const gsl_function functionBc = {.function = integrandBc, .params = p};
    const double bc = gsl_integration_glfixed(&functionBc, 0, 2 * M_PI, GaussTable::get());

    const gsl_function functionDbc = {.function = integrandDbc, .params = p};
    const double dbc = gsl_integration_glfixed(&functionDbc, 0, 2 * M_PI, GaussTable::get());

    return -15 / (32 * M_PI) * bc - 15 * p->R0 / (16 * ac * M_PI) * dbc;
}

double CoulombEnergy::integrandBc(double fi, void* params) {
    const Params* p = static_cast<Params*>(params);
    const double ro1 = p->ro1;
    const double ro2 = p->ro2;
    const double ro1pow2 = p->ro1pow2;
    const double ro2pow2 = p->ro2pow2;
    const double dro2dz1 = p->dro2dz1;
    const double dro2dz2 =p->dro2dz2;
    const double deltaz = p->deltaz;
    double sigma = sqrt(ro1pow2 + ro2pow2 - 2 * ro1 * ro2 * cos(fi) + pow(deltaz, 2));
    return sigma * (ro1 * ro2 * cos(fi) + 1. / 4 * dro2dz1 * dro2dz2);
}

double CoulombEnergy::integrandDbc(double fi, void* params) {
    const Params* p = static_cast<Params*>(params);
    const double ro1 = p->ro1;
    const double ro2 = p->ro2;
    const double ro1pow2 = p->ro1pow2;
    const double ro2pow2 = p->ro2pow2;
    const double drodz1 = p->drodz1;
    const double drodz2 = p->drodz2;
    const double deltaz = p->deltaz;
    const double R0 = p->R0;
    const double tmp = sqrt(ro1pow2 + ro2pow2 - 2 * ro1 * ro2 * cos(fi) + pow(deltaz, 2)) * R0 / ac;
    double fun = (2. * tmp - 5. + (0.5 * pow(tmp, 2) + 3. * tmp + 5.) * exp(-tmp)) / pow(tmp, 4);
    return fun * ro1 * (ro1 - ro2 * cos(fi) + drodz1 * deltaz) * ro2 * (ro2 - ro1 * cos(fi) - drodz2 * deltaz);
}
