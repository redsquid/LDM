#ifndef VOLUME_H
#define VOLUME_H

#include "Shape.h"

class Volume {
public:
    Volume() = delete;
    static double calculate(const Shape& shape);

private:
    static double integrand(double z, void* params);
};

#endif // VOLUME_H
