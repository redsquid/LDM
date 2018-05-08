#include "CoulombEnergySharp.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

struct Params {
    double z1;
    double z2;
    double ro1;
    double ro2;
    double ro1pow2;
    double ro2pow2;
    Shape* shape;
};

CoulombEnergySharp::CoulombEnergySharp(const uint A, const uint Z) :
    ec0_(pac * pow(Z, 2) / pow(A, (1. / 3)))
{
}

CoulombEnergySharp::~CoulombEnergySharp() {
}

double CoulombEnergySharp::operator ()(const Shape& s) const {
    return (15. / (4 * M_PI) * calcI1(s) - 1) * ec0_;
}

double CoulombEnergySharp::calcI1(const Shape& s) {
    Shape shape(s);
    Params p;
    p.shape = &shape;
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, p.shape->zmin(), p.shape->zmax(), GaussTable::get());
}

double CoulombEnergySharp::calcI2(double z, void* params) {
    Params* p = static_cast<Params*>(params);
    p->z1 = z;
    p->ro1 = p->shape->value(z);
    p->ro1pow2 = p->shape->pow2(z);
    const gsl_function function = {.function = calcI3, .params = p};
    return gsl_integration_glfixed(&function, p->shape->zmin(), z, GaussTable::get());
}

double CoulombEnergySharp::calcI3(double z, void* params) {
    Params* p = static_cast<Params*>(params);
    p->z2 = z;
    p->ro2 = p->shape->value(z);
    p->ro2pow2 = p->shape->pow2(z);
    const gsl_function function = {.function = integrand, .params = p};
    return gsl_integration_glfixed(&function, 0, M_PI, GaussTable::get());
}

double CoulombEnergySharp::integrand(double teta, void* params) {
    const Params* p = static_cast<Params*>(params);
    const double z1 = p->z1;
    const double z2 = p->z2;
    const double ro1 = p->ro1;
    const double ro2 = p->ro2;
    const double ro1pow2 = p->ro1pow2;
    const double ro2pow2 = p->ro2pow2;
    double f = sqrt(ro1pow2 + ro2pow2 - 2 * ro1 * ro2 * cos(teta) + pow((z1 - z2), 2));
    return ro1pow2 * ro2pow2 * pow(sin(teta), 2) / (z1 - z2 + f) ;
}
