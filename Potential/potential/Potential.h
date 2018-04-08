#ifndef POTENTIAL_H
#define POTENTIAL_H

#include "Shape.h"

#include <cstdlib>

class Potential {
public:
    Potential(const uint vA, const uint vZ);
    virtual ~Potential();
    double operator() (const Shape& shape, const double vI, const double vK);

private:
    const int vA_;
    const int vZ_;
};

#endif // POTENTIALSHARP_H
