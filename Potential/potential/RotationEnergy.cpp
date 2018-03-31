#include "RotationEnergy.h"

#include "math.h"
#include "const/Const.h"

using C = Const;

const size_t RotationEnergy::ORDER = 32;

static double j_par(double z, void* params);

static double j_perp(double z, void* params);

RotationEnergy::RotationEnergy(const uint vA) :
    GAUSS_FIXED_TABLE(gsl_integration_glfixed_table_alloc(ORDER)),
    J0(2. / 5 * C::m0 * pow(C::r0, 2) * pow(vA, 5. / 3))
{
}

RotationEnergy::~RotationEnergy() {
    gsl_integration_glfixed_table_free(GAUSS_FIXED_TABLE);
}

double RotationEnergy::operator() (const Shape& shape, const double vI, const double vK) const {
    return pow(C::hbar, 2) * pow(vK, 2) / (2 * getJpar(shape)) +
            pow(C::hbar, 2) * (vI * (vI + 1) - pow(vK, 2)) / (2 * getJperp(shape));
}

double RotationEnergy::getJpar(const Shape& shape) const {
    const gsl_function j_par_fun = {.function = j_par, .params = const_cast<Shape*>(&shape)};
    return J0 * (15. / 16) * gsl_integration_glfixed(&j_par_fun, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);

}

double RotationEnergy::getJperp(const Shape& shape) const {
    const gsl_function j_perp_fun = {.function = j_perp, .params = const_cast<Shape*>(&shape)};
    return J0 * (15. / 32) * gsl_integration_glfixed(&j_perp_fun, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);

}

static double j_par(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return pow(shape(z), 4);
}

static double j_perp(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return pow(shape(z), 2) * (4 * pow(z, 2) + pow(shape(z), 2));
}
