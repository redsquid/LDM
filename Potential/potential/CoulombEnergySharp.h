#ifndef COULOMBENERGYSHARP_H
#define COULOMBENERGYSHARP_H

#include "Shape.h"

#include <cstdlib>

/**
 * LDM W. D. Myers, W. J. Swiatecki
 *
 */
class CoulombEnergySharp {
public:
    CoulombEnergySharp(const uint A, const uint Z);
    virtual ~CoulombEnergySharp();
    double operator ()(const Shape& shape) const;

private:
    class Params {
    public:
        Params(double z1, double z2, const Shape& shape) : Z1(z1), Z2(z2), SHAPE(shape) {}
        const double Z1;
        const double Z2;
        const Shape& SHAPE;
    };

    static constexpr double r0 = 1.2249; // fm
    static constexpr double pac = 0.705352;

    static double calcI1(Params& p);
    static double calcI2(double z, void* params);
    static double calcI3(double z, void* params);
    static double integrand(double teta, void* params);

    const double ec0_;

};

#endif // COULOMBENERGYSHARP_H
