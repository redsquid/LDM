#include "CoulombEnergySharp.h"

#include <iostream>
#include "const/Const.h"

const size_t CoulombEnergySharp::ORDER = 32;
static double calcBcI2(double z, void* params);

struct Params {
    const double z1;
    const double z2;
    const Shape& shape;
    gsl_integration_glfixed_table* goussFixedTable;
};


CoulombEnergySharp::CoulombEnergySharp(const uint A, const uint Z) :
GAUSS_FIXED_TABLE(gsl_integration_glfixed_table_alloc(ORDER)),
ec0_(3 / 5. * pow(Const::e, 2) * pow(Z, 2) / (Const::r0 * pow(A, 1 / 3.)))
{
}

CoulombEnergySharp::~CoulombEnergySharp() {
    gsl_integration_glfixed_table_free(GAUSS_FIXED_TABLE);
}

static double fun(double teta, void* params) {

    const Params p = *(static_cast<Params*>(params));
    const double z1 = p.z1;
    const double z2 = p.z2;
    const Shape& s = p.shape;

    double f = sqrt(s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(teta) + pow((z1 - z2), 2));
    return s.pow2(z1) * s.pow2(z2) * pow(sin(teta), 2) / (z1 - z2 + f) ;
}

static double calcBcI3(double z, void* params) {

    const Params tmp = *(static_cast<Params*>(params));
    const double z1 = tmp.z1;
    const Shape& shape = tmp.shape;
    gsl_integration_glfixed_table* gsft = tmp.goussFixedTable;


    Params p = {.z1 = z1, .z2 = z, .shape = shape, .goussFixedTable = gsft};
    const gsl_function function = {.function = fun, .params = &p};

    return gsl_integration_glfixed(&function, 0, M_PI, gsft);
}


static double calcBcI2(double z, void* params) {

    const Params tmp = *(static_cast<Params*>(params));
    const Shape& shape = tmp.shape;
    gsl_integration_glfixed_table* gsft = tmp.goussFixedTable;


    Params p = {.z1 = z, .z2 = 0, .shape = shape, .goussFixedTable = gsft};
    const gsl_function function = {.function = calcBcI3, .params = &p};

    return gsl_integration_glfixed(&function, -shape.getC(), z, gsft);
}

double CoulombEnergySharp::operator ()(const Shape& shape) const {

    Params p = {.z1 = 0, .z2 = 0, .shape = shape, .goussFixedTable = GAUSS_FIXED_TABLE};
    const gsl_function function = {.function = calcBcI2, .params = &p};
    return ec0_ * 15. / (4 * M_PI) * gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);
}

double CoulombEnergySharp::ec0() const {
    return ec0_;
}





