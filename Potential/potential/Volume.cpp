#include "Volume.h"

#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

double Volume::calculate(const Shape& shape) {
    const gsl_function function = {.function = integrand, .params = const_cast<Shape*>(&shape)};
    return M_PI *  gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GaussTable::get());
}

double  Volume::integrand(double z, void* params) {
    Shape& shape = *(static_cast<Shape*>(params));
    return shape.pow2(z);
}
