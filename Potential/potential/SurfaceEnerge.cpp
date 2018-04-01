#include "SurfaceEnerge.h"
#include "const/Const.h"

struct Params {
    const double z1;
    const double z2;
    const double cs;
    const Shape& shape;
    gsl_integration_glfixed_table* goussFixedTable;
};

SurfaceEnerge::SurfaceEnerge(const uint vA, const uint vZ , const double vEs0Sharp) :
    GAUSS_FIXED_TABLE(gsl_integration_glfixed_table_alloc(ORDER)),
    vR0_(r0 * pow(vA, 1. / 3)),
    cs_(as * (1 - ks * pow(vA - 2 * vZ, 2) / pow(vA, 2))),
    e0_(vEs0Sharp * (1 - 3 * pow(a / vR0_, 2) + (vR0_ / a + 1) * (2 + 3 * a / vR0_ + 3 * pow(a / vR0_, 2)) * exp(-2 * vR0_ / a)))
{
}

SurfaceEnerge::~SurfaceEnerge() {
    gsl_integration_glfixed_table_free(GAUSS_FIXED_TABLE);
}

double SurfaceEnerge::fun(double fi, void* params) {

    const Params p = *(static_cast<Params*>(params));
    const double z1 = p.z1;
    const double z2 = p.z2;
    const double cs = p.cs;
    const Shape& s = p.shape;

    const double sigma = sqrt(pow((z1 - z2), 2) + s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(fi));

    const double f = -cs / (4 * M_PI * pow(r0, 2) * pow(sigma, 4))
            * (2 - (2 + 2 * sigma / a + pow(sigma / a, 2)) * exp(-sigma / a));

    return f * s(z1) * (s(z1) - s(z2) * cos(fi) - s.deriv(z1) * (z1 - z2))
            * s(z2) * (s(z2) -s(z1) * cos(fi) + s.deriv(z2) * (z1 - z2));
}

double SurfaceEnerge::calcBcI3(double z, void* params) {
    const Params tmp = *(static_cast<Params*>(params));
    const double z1 = tmp.z1;
    const Shape& shape = tmp.shape;
    gsl_integration_glfixed_table* gsft = tmp.goussFixedTable;
    Params p = {.z1 = z1, .z2 = z, .cs = tmp.cs, .shape = shape, .goussFixedTable = gsft};
    const gsl_function function = {.function = fun, .params = &p};
    return gsl_integration_glfixed(&function, 0, 2 * M_PI, gsft);
}

double SurfaceEnerge::calcBcI2(double z, void* params) {
    const Params tmp = *(static_cast<Params*>(params));
    const Shape& shape = tmp.shape;
    gsl_integration_glfixed_table* gsft = tmp.goussFixedTable;
    Params p = {.z1 = z, .z2 = 0, .cs = tmp.cs, .shape = shape, .goussFixedTable = gsft};
    const gsl_function function = {.function = calcBcI3, .params = &p};
    return gsl_integration_glfixed(&function, -shape.getC(), -shape.getC(), gsft);
}

double SurfaceEnerge::operator ()(const Shape& shape) const {
    Params p = {.z1 = 0, .z2 = 0, .cs = cs_, .shape = shape, .goussFixedTable = GAUSS_FIXED_TABLE};
    const gsl_function function = {.function = calcBcI2, .params = &p};
    return gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);
}

double SurfaceEnerge::e0() const {
    return e0_;
}
