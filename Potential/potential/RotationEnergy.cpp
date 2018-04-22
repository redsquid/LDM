#include "RotationEnergy.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

RotationEnergy::RotationEnergy(const uint vA, const uint vZ) :
    m0((931.5016 * vA - 0.511004 * vZ) / (2.998 * 2.998) / 10000. / vA),
    J0(2. / 5 * m0 * pow(r0, 2) * pow(vA, 5. / 3)),
    er0(0.5 * Const::hpl * Const::hpl / J0),
    vR0_(r0 * pow(vA, 1. / 3))
{
}

RotationEnergy::~RotationEnergy() {
}

double RotationEnergy::operator() (const Shape& shape, const int vL, const int vK) const {
    const double jpar = calcJpar(shape);
    const double jperp = calcJperp(shape) - 5. / 2 * pow(shape.zcm(), 2);

    const double afd = 10 * pow(ac, 2) / pow(vR0_, 2);
    const double j = 1 / (jperp + afd);
    const double k = (jperp - jpar) * j / (jpar + afd);

    return er0 * pow(vL, 2) * j + er0 * k * pow(vK, 2);
}

double RotationEnergy::calcJpar(const Shape& shape) const {
    const gsl_function function = {.function = jparIntegrand, .params = const_cast<Shape*>(&shape)};
    return (15. / 16) * gsl_integration_glfixed(&function, shape.zmin(), shape.zmax(), GaussTable::get());
}

double RotationEnergy::calcJperp(const Shape& shape) const {
    const gsl_function function = {.function = jperpIntegrand, .params = const_cast<Shape*>(&shape)};
    return (15. / 32) * gsl_integration_glfixed(&function, shape.zmin(), shape.zmax(), GaussTable::get());
}

double RotationEnergy::jparIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s.pow2(z), 2);
}

double RotationEnergy::jperpIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return s.pow2(z) * (4 * pow(z, 2) + s.pow2(z));
}
