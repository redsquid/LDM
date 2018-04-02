#include "PotentialSharp.h"

#include "SurfaceEnergySharp.h"
#include "CoulombEnergySharp.h"
#include "RotationEnergySharp.h"

PotentialSharp::PotentialSharp(const uint vA, const uint vZ) :
    vA_(vA),
    vZ_(vZ)
{
}

PotentialSharp::~PotentialSharp() {
}

double PotentialSharp::operator() (const Shape& shape, const double vI, const double vK) {
    const SurfaceEnergySharp es(vA_, vZ_);
    const CoulombEnergySharp ec(vA_, vZ_);
    const RotationEnergySharp er(vA_);
    return (es(shape) - es.es0()) + (ec(shape) - ec.ec0()) + er(shape, vI, vK);
}
