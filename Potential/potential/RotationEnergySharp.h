#ifndef ROTATIONENERGYSHARP_H
#define ROTATIONENERGYSHARP_H

#include "Shape.h"

#include <cstdlib>

#include "const/Const.h"

/**
 * LDM W. D. Myers, W. J. Swiatecki
 *
 */
class RotationEnergySharp {
public:
    RotationEnergySharp(const uint vA);
    virtual ~RotationEnergySharp();
    double operator() (const Shape& shape, const int vL, const int vK) const;

private:
    double calcJpar(const Shape& shape) const;
    double calcJperp(const Shape& shape) const;
    static double jparIntegrand(double z, void* params);
    static double jperpIntegrand(double z, void* params);

    static constexpr double r0 = 1.2249; //fm
    //static constexpr double am = 0.704; // fm  [29]

    const double J0;
    const double er0;

    //const double mass;

    static constexpr double m0 = 0.01044893;

};

#endif // ROTATIONENERGYSHARP_H
