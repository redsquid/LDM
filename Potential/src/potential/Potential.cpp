#include "Potential.h"

#include "RotationEnergySharp.h"

#include "CoulombEnergySharp.h"
#include <iostream>
#include "SurfaceEnergySharp.h"



Potential::Potential(const uint vA, const uint vZ) :
    se(vA, vZ),
    ce(vA, vZ),
    re(vA, vZ)
{
}

Potential::~Potential() {
}

double Potential::operator() (const Shape& shape, const double vL, const double vK) const {
    return se(shape) + ce(shape) + re(shape, vL, vK);
}
