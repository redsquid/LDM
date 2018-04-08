#include "CoulombEnergySharp.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

CoulombEnergySharp::CoulombEnergySharp(const uint A, const uint Z) :
    //ec0_(3. / 5 * pow(Const::e, 2) * pow(Z, 2) / (r0 * pow(A, 1 / 3.)))
    ec0_(pac * Z * Z / pow(A, (1. / 3)))
{
}

CoulombEnergySharp::~CoulombEnergySharp() {
}

double CoulombEnergySharp::ec0() const {
    return ec0_;
}

double CoulombEnergySharp::operator ()(const Shape& s) const {
    Params p(0, 0, s);
    return 15. / (4 * M_PI) * calcI1(p) * ec0_;
}

double CoulombEnergySharp::calcI1(Params& p) {
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, -p.SHAPE.getC(), p.SHAPE.getC(), GaussTable::get());
}

double CoulombEnergySharp::calcI2(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(z, 0, tmp.SHAPE);
    const gsl_function function = {.function = calcI3, .params = &p};
    return gsl_integration_glfixed(&function, -p.SHAPE.getC(), z, GaussTable::get());
}

double CoulombEnergySharp::calcI3(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(tmp.Z1, z, tmp.SHAPE);
    const gsl_function function = {.function = integrand, .params = &p};
    return gsl_integration_glfixed(&function, 0, M_PI, GaussTable::get());
}

double CoulombEnergySharp::integrand(double teta, void* params) {
    const Params& p = *(static_cast<Params*>(params));
    const double z1 = p.Z1;
    const double z2 = p.Z2;
    const Shape& s = p.SHAPE;
    double f = sqrt(s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(teta) + pow((z1 - z2), 2));
    return s.pow2(z1) * s.pow2(z2) * pow(sin(teta), 2) / (z1 - z2 + f) ;
}
