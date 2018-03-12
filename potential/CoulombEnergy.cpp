#include "CoulombEnergy.h"

#include <iostream>
const size_t CoulombEnergy::ORDER = 32;
static double calcBcI2(double z, void* params);

struct Params {
    const double z1;
    const double z2;
    const Shape& shape;
    gsl_integration_glfixed_table* goussFixedTable;
};

CoulombEnergy::CoulombEnergy(const uint A, const uint Z) :
GAUSS_FIXED_TABLE(gsl_integration_glfixed_table_alloc(ORDER)){
}

CoulombEnergy::~CoulombEnergy() {
    gsl_integration_glfixed_table_free(GAUSS_FIXED_TABLE);
}





static double fun(double teta, void* params) {

    const Params p = *(static_cast<Params*>(params));
    const double z1 = p.z1;
    const double z2 = p.z2;
    const Shape& s = p.shape;

//    return (s.pow2(z1) * s.pow2(z2) * cos(teta) + 1 / 4. * s.deriv(z1) * s.deriv(z2)) *
//            sqrt(s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(teta) + pow((z1 - z2), 2));

    double f = sqrt(s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(teta) + pow((z1 - z2), 2));
    return s.pow2(z1) * s.pow2(z2) * pow(sin(teta), 2) / (z1 - z2 + f) ;

//    return teta * z2 * z1;
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

double CoulombEnergy::operator ()(Shape& shape) {


    Params p = {.z1 = 1, .z2 = 1, .shape = shape, .goussFixedTable = GAUSS_FIXED_TABLE};
    const gsl_function function = {.function = calcBcI2, .params = &p};


    return 15. / (4 * M_PI) * gsl_integration_glfixed(&function, -shape.getC(), shape.getC(), GAUSS_FIXED_TABLE);
}





