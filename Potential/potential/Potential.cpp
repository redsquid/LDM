#include "Potential.h"

#include "SurfaceEnergy.h"
#include "CoulombEnergy.h"
#include "RotationEnergySharp.h"

#include "CoulombEnergySharp.h"
#include <iostream>
#include "SurfaceEnergySharp.h"

#include "RotationEnergy.h"

Potential::Potential(const uint vA, const uint vZ) :
    vA_(vA),
    vZ_(vZ)
{
}

Potential::~Potential() {
}

double Potential::operator() (const Shape& shape, const double vL, const double vK) {
    //const SurfaceEnergy es(vA_, vZ_);
    const CoulombEnergy ce(vA_, vZ_);
    //const RotationEnergy re(vA_, vZ_);

    //const CoulombEnergySharp ecsharp(vA_, vZ_);
    //const SurfaceEnergySharp essharp(vA_, vZ_);
    //const RotationEnergySharp er(vA_);

    return ce(shape);//re(shape, vL, vK); //essharp(shape) - essharp.es0() + es(shape);
    //essharp(shape) - essharp.es0() + ecsharp(shape) - ecsharp.ec0();
    // + er(shape, vI, vK);
}
