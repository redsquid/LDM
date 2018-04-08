#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "gsl/gsl_const_mksa.h"
#include "gsl/gsl_const.h"

class Const {
public:
    static constexpr double r0 = 1.2249; //fm

    static constexpr double as = 17.9439; //MeV
    static constexpr double ks = 1.7826;

    static constexpr double e = 1;
    static constexpr double hpl = 0.6582119514; //MeV * (s * 10^-21)
    static constexpr double m0 = 931.4940954; //MeV
};

#endif // CONSTANTS_H



