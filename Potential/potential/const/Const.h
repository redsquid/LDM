#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "gsl/gsl_const_mksa.h"

class Const {
public:
    static constexpr double r0 = 1.2249; //fm
    static constexpr double as = 17.9439; //MeV
    static constexpr double ks = 1.7826;
    static constexpr double e = GSL_CONST_MKSA_ELECTRON_CHARGE;

};

#endif // CONSTANTS_H



