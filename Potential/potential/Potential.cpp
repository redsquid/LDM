#include "Potential.h"

#include "SurfaceEnergy.h"
#include "CoulombEnergy.h"
#include "RotationEnergy.h"

#include "CoulombEnergySharp.h"
#include <iostream>
#include "SurfaceEnergySharp.h"

Potential::Potential(const uint vA, const uint vZ) :
    vA_(vA),
    vZ_(vZ)
{
}

Potential::~Potential() {
}

double Potential::operator() (const Shape& shape, const double vI, const double vK) {
    const SurfaceEnergy es(vA_, vZ_);
    const CoulombEnergy ec(vA_, vZ_);
    const RotationEnergy er(vA_);

    const CoulombEnergySharp ecsharp(vA_, vZ_);
    const SurfaceEnergySharp essharp(vA_, vZ_);

    return ecsharp(shape) - ecsharp.ec0(); //essharp(shape) - essharp.es0() + ecsharp(shape) - ecsharp.ec0(); // + er(shape, vI, vK);
}
