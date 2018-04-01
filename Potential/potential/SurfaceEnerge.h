#ifndef SURFACEENERGE_H
#define SURFACEENERGE_H

#include <cstdlib>
#include <gsl/gsl_integration.h>
#include "Shape.h"

class SurfaceEnerge {
public:
    SurfaceEnerge(const uint vA, const uint vZ , const double vEs0Sharp);
    virtual ~SurfaceEnerge();

    double operator ()(const Shape& shape) const;
    double e0() const;
private:
    static double calcBcI2(double z, void* params);
    static double calcBcI3(double z, void* params);
    static double fun(double fi, void* params);

    static constexpr size_t ORDER = 32;
    gsl_integration_glfixed_table* GAUSS_FIXED_TABLE;

    static constexpr double a = 0.68; // Fm Yukava potential parameter
    static constexpr double as = 21.13; // MeV
    static constexpr double ks = 2.3;
    static constexpr double r0 = 1.16;  // Fm
    static constexpr double am = 0.704; //Fm
    static constexpr double ad = 0.704; //Fm

    const double vR0_;
    const double cs_;
    const double e0_;

};

#endif // SURFACEENERGE_H
