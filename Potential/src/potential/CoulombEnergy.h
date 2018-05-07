#ifndef COULOMBENERGY_H
#define COULOMBENERGY_H

#include "CoulombEnergySharp.h"

class CoulombEnergy {
public:
    CoulombEnergy(const uint vA, const uint vZ);
    virtual ~CoulombEnergy();
    double operator ()(const Shape& shape) const;

private:
    double calcI1(const Shape& shape) const;
    static double calcI2(double z, void* params);
    static double calcI3(double z, void* params);

    static double integrandBc(double fi, void* params);
    static double integrandDbc(double fi, void* params);

    static constexpr double r0 = 1.16;  // Fm
    static constexpr double pac = 0.7448154;
    static constexpr double ac = 0.704;

    const double vR0_;
    const double ec0_;
    const double dec_;
};

#endif // COULOMBENERGY_H
