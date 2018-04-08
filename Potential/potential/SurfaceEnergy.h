#ifndef SURFACEENERGE_H
#define SURFACEENERGE_H

#include "Shape.h"

#include <cstdlib>

#include "SurfaceEnergySharp.h"

class SurfaceEnergy {
public:
    SurfaceEnergy(const uint vA, const uint vZ);
    virtual ~SurfaceEnergy();

    double operator ()(const Shape& shape) const;
    double es0() const;
private:
    double calcI1(const Shape& shape) const;
    static double calcI2(double z, void* params);
    static double calcI3(double z, void* params);
    static double integrand(double fi, void* params);

    static constexpr double a = 0.68; // Fm Yukava potential parameter
    static constexpr double as = 21.13; // MeV
    static constexpr double ks = 2.3;
    static constexpr double r0 = 1.16;  // Fm
    static constexpr double am = 0.704; //Fm
    static constexpr double ad = 0.704; //Fm

    SurfaceEnergySharp essharp;

    const double vR0_;
    const double cs_;
    const double es0_;

    class Params {
    public:
        Params(double z1, double z2, double cs, const Shape& shape) : Z1(z1), Z2(z2), CS(cs), SHAPE(shape) {}
        const double Z1;
        const double Z2;
        const double CS;
        const Shape& SHAPE;
    };
};

#endif // SURFACEENERGE_H
