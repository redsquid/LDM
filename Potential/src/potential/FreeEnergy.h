#ifndef FREEENERGY_H
#define FREEENERGY_H

#include "Potential.h"
#include "SurfaceEnergySharp.h"

class FreeEnergy {
public:
    FreeEnergy(const uint vA, const uint vZ, const double vT);
    virtual ~FreeEnergy();
    double operator ()(const Shape& shape, const double vL, const double vK) const;

private:
    static double calcBs(const Shape& shape);
    static double integrand(double z, void* params);

    const Potential potential;
    const SurfaceEnergySharp sesharp;
    const double vA_;
    const double vTpow2_;

    static constexpr double av = 0.073; // MeV Игнатюк А.В. и др. ЯФ. 1975. Том 21. С. 1185-1205
    static constexpr double as = 0.095; // MeV


};

#endif // FREEENERGY_H
