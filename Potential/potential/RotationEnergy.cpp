#include "RotationEnergy.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

RotationEnergy::RotationEnergy(const uint vA) :
    J0(2. / 5 * Const::m0 * pow(Const::r0, 2) * pow(vA, 5. / 3)),
    mass(Const::m0 * vA)
{
}

RotationEnergy::~RotationEnergy() {
}

double RotationEnergy::operator() (const Shape& shape, const double vI, const double vK) const {
    return pow(Const::hpl, 2) * pow(vK, 2) / (2 * calcJpar(shape)) +
            pow(Const::hpl, 2) * (vI * (vI + 1) - pow(vK, 2)) / (2 * calcJperp(shape));
}

double RotationEnergy::calcJpar(const Shape& shape) const {
    const gsl_function function = {.function = jparIntegrand, .params = const_cast<Shape*>(&shape)};
    return J0 * (15. / 16) * gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GaussTable::get());
            //+ 4 * mass * pow(am, 2);
}

double RotationEnergy::calcJperp(const Shape& shape) const {
    const gsl_function function = {.function = jperpIntegrand, .params = const_cast<Shape*>(&shape)};
    return J0 * (15. / 32) * gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GaussTable::get());
            //+ 4 * mass * pow(am, 2);
}

double RotationEnergy::jparIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s(z), 4);
}

double RotationEnergy::jperpIntegrand(double z, void* params) {
    Shape& s = *(static_cast<Shape*>(params));
    return pow(s(z), 2) * (4 * pow(z, 2) + pow(s(z), 2));
}
