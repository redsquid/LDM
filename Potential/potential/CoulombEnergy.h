#ifndef COULOMBENERGY_H
#define COULOMBENERGY_H

#include "CoulombEnergySharp.h"

class CoulombEnergy {
public:
    CoulombEnergy(const uint vA, const uint vZ);
    virtual ~CoulombEnergy();

    double operator ()(const Shape& shape) const;
    double ec0() const;
private:
    double calcI1(const Shape& shape) const;
    static double calcI2(double z, void* params);
    static double calcI3(double z, void* params);
    static double integrand(double fi, void* params);

    static constexpr double r0 = 1.16;  // Fm
    static constexpr double pac = 0.7448154;
    static constexpr double ac = 0.704;

    const double vR0_;
    const double ec0_;
    const double dec_;




    class Params {
    public:
        Params(double z1, double z2, double vR0, double ec0, const Shape& shape) :
            Z1(z1), Z2(z2), R0(vR0), EC0(ec0), SHAPE(shape) {}
        const double Z1;
        const double Z2;
        const double R0;
        const double EC0;
        const Shape& SHAPE;
    };
};

#endif // COULOMBENERGY_H
