#ifndef COULOMBENERGYSHARP_H
#define COULOMBENERGYSHARP_H

#include "Shape.h"

#include <cstdlib>

class CoulombEnergySharp {
public:
    CoulombEnergySharp(const uint A, const uint Z);
    virtual ~CoulombEnergySharp();
    double operator ()(const Shape& shape) const;
    double ec0() const;

private:
    class Params {
    public:
        Params(double z1, double z2, const Shape& shape) : Z1(z1), Z2(z2), SHAPE(shape) {}
        const double Z1;
        const double Z2;
        const Shape& SHAPE;
    };

    static double calcI1(Params& p);
    static double calcI2(double z, void* params);
    static double calcI3(double z, void* params);
    static double integrand(double teta, void* params);
    const double ec0_;
};

#endif // COULOMBENERGYSHARP_H
