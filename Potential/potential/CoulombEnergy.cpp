#include "CoulombEnergy.h"

#include "const/Const.h"
#include "const/GaussTable.h"

#include <gsl/gsl_integration.h>

#include <iostream>

CoulombEnergy::CoulombEnergy(const uint vA, const uint vZ) :
    vR0_(r0 * pow(vA, 1. / 3)),
    ec0_(pac * pow(vZ, 2) / pow(vA, 1. / 3)),
    dec_(1 - 5. / pow(vR0_ / ac, 2) * (1 - 15. / (8 * vR0_ / ac) + 21. / (8 * pow(vR0_ / ac, 3))
         - 0.75 * (1 + 9./ (2 * vR0_ / ac) + 7. / pow(vR0_ / ac, 2) + 7. / (2. * pow(vR0_ / ac, 3)))
         * exp(-2. * vR0_ / ac)))

{


//    //0.962049
    //double Dec0 = 1 - 5. / pow(vR0_ / ac, 2) * (1 - 15. / (8 * vR0_ / ac) + 21. / (8 * pow(vR0_ / ac, 3)) - 0.75 * (1 + 9./ (2 * vR0_ / ac) + 7. / pow(vR0_ / ac, 2) + 7. / (2. * pow(vR0_ / ac, 3))) * exp(-2. * vR0_ / ac));

    //std::cout << dec_ << std::endl;
    //exit(0);



}

CoulombEnergy::~CoulombEnergy() {
}

double CoulombEnergy::operator ()(const Shape& shape) const {

    return (calcI1(shape) - dec_) * ec0_;

    //dbc
    //return  15 * vR0_ / (16 * ac * M_PI)  * calcI1(shape);

    //bc
    //return -15 / (32 * M_PI) * calcI1(shape);

}

double CoulombEnergy::calcI1(const Shape& s) const {
    Params p(0, 0, vR0_, 0, s);
    const gsl_function function = {.function = calcI2, .params = &p};
    return gsl_integration_glfixed(&function, -s.zmax(), s.zmax(), GaussTable::get());
}

double CoulombEnergy::calcI2(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(z, 0, tmp.R0, tmp.EC0, tmp.SHAPE);
    const gsl_function function = {.function = calcI3, .params = &p};
    return gsl_integration_glfixed(&function, -tmp.SHAPE.zmax(), tmp.SHAPE.zmax(), GaussTable::get());
}

double CoulombEnergy::calcI3(double z, void* params) {
    const Params& tmp = *(static_cast<Params*>(params));
    Params p(tmp.Z1, z,  tmp.R0, tmp.EC0, tmp.SHAPE);

    const gsl_function functionBc = {.function = integrandBc, .params = &p};
    const double bc = gsl_integration_glfixed(&functionBc, 0, 2 * M_PI, GaussTable::get());

    const gsl_function functionDbc = {.function = integrandDbc, .params = &p};
    const double dbc = gsl_integration_glfixed(&functionDbc, 0, 2 * M_PI, GaussTable::get());

    return -15 / (32 * M_PI) * bc - 15 * tmp.R0 / (16 * ac * M_PI) * dbc;
}

double CoulombEnergy::integrandBc(double fi, void* params) {
    const Params& p = *(static_cast<Params*>(params));
    const double z1 = p.Z1;
    const double z2 = p.Z2;
    const double vR0 = p.R0;
    const double ec0 = p.EC0;
    const Shape& s = p.SHAPE;

    //bc
    double rh = z1 - z2;
    double r2 = s(z1);
    double r3 = s(z2);
    double r22 = s.pow2(z1);
    double r33 = s.pow2(z2);
    double dp2 = s.deriv2(z1); //pow(s.deriv(z1), 2);
    double dph2 = s.deriv2(z2); //pow(s.deriv(z2), 2);

    double co = cos(fi);
    double term = r2 * r3 * co;
    double rm2 = r22 + r33 - 2 * term + rh * rh;
    double rm = sqrt(rm2);

    return (term + 0.25 * dp2 * dph2) * rm;

}

double CoulombEnergy::integrandDbc(double fi, void* params) {
    const Params& p = *(static_cast<Params*>(params));
    const double z1 = p.Z1;
    const double z2 = p.Z2;
    const double vR0 = p.R0;
    const double ec0 = p.EC0;
    const Shape& s = p.SHAPE;


    //dbc
    const double sigma = sqrt(s.pow2(z1) + s.pow2(z2) - 2 * s(z1) * s(z2) * cos(fi) + pow(z1 - z2, 2));
    double armc = vR0 / ac;
    double otnc = sigma * armc;
    double otnc2 = otnc * otnc;
    double otnc4 = otnc2 * otnc2;
    double fund = (2. * otnc - 5. + (0.5 * otnc2 + 3. * otnc + 5.) * exp(-otnc)) / otnc4;
    return fund * s(z1) * (s(z1) - s(z2) * cos(fi) - s.deriv(z1) * (z1 - z2))
            * s(z2) * (s(z2) - s(z1) * cos(fi) - s.deriv(z2) * (z2 - z1));

}
