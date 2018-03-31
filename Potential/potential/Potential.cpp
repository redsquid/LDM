#include "Potential.h"

#include "SurfaceEnergy.h"
#include "CoulombEnergy.h"
#include "RotationEnergy.h"

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

    return (es(shape) - es.es0()) + (ec(shape) - ec.ec0()) + er(shape, vI, vK);
}
