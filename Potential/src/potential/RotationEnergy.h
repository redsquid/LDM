#ifndef ROTATIONENERGY_H
#define ROTATIONENERGY_H

#include "Shape.h"

#include <cstdlib>

#include "const/Const.h"

/**
 * FRLDM
 *
 */
class RotationEnergy {
public:
    RotationEnergy(const uint vA, const uint vZ);
    virtual ~RotationEnergy();
    double operator() (const Shape& shape, const int vL, const int vK) const;

private:
    double calcJpar(const Shape& shape) const;
    double calcJperp(const Shape& shape) const;
    static double jparIntegrand(double z, void* params);
    static double jperpIntegrand(double z, void* params);

    static constexpr double r0 = 1.16; //fm
    static constexpr double ac = 0.704; //fm

    const double m0;
    const double J0;
    const double er0;
    const double vR0_;
};

#endif // ROTATIONENERGY_H
