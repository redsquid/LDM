#ifndef POTENTIALSHARP_H
#define POTENTIALSHARP_H

#include <cstdlib>
#include "Shape.h"

class PotentialSharp {
public:
    PotentialSharp(const uint vA, const uint vZ);
    virtual ~PotentialSharp();

    double operator() (const Shape& shape, const double vI, const double vK);

private:
    const int vA_;
    const int vZ_;
};

#endif // POTENTIALSHARP_H