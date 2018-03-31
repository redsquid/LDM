#ifndef POTENTIAL_H
#define POTENTIAL_H

#include <cstdlib>
#include "Shape.h"

class Potential {
public:
    Potential(const uint vA, const uint vZ);
    virtual ~Potential();

    double operator() (const Shape& shape, const double vI, const double vK);

private:
    const int vA_;
    const int vZ_;
};

#endif // POTENTIAL_H
