#include "Shape.h"

#include <gsl/gsl_math.h>

Shape::Shape(const double _c, const double _h, const double _alpha) :
    c_(_c),
    h_(_h),
    a_(_alpha),
    b_(calcB(c_, h_)),
    as_(calcAs(c_, b_))
{
}

Shape::~Shape() {}

double Shape::operator() (const double z) const {
    return sqrt(pow2(z));
}

double Shape::pow2(const double z) const {
    double result = (b_ >= 0) ? (pow(c_, 2) - pow(z, 2)) * (as_ + b_ * pow(z, 2) / pow(c_, 2) + a_ * z / c_) :
                               (pow(c_, 2) - pow(z, 2)) * (as_ + a_ * z / c_) * exp(b_ * c_ * pow(z, 2));
    return (result < 0) ? 0 : result;
}

double Shape::deriv(const double _z) const {
    const double dz = 1e-10;
    double z = ((c_ - fabs(_z)) < dz) ? _z - GSL_SIGN(_z) * dz : _z;
    return (this->operator ()(z + dz) - this->operator ()(z - dz)) / (2 * dz);
}

double Shape::getC() const {
    return c_;
}

double Shape::calcB(const double c, const double h) {
    return 2 * h + (c - 1) / 2;
}

double Shape::calcAs(const double c, const double _b) {
    double b = (fabs(_b) < 1e-5) ? 0 : _b;
    return (b >= 0) ? pow(c, -3) - b / 5 :
            -4. / 3 * b / (exp(b * pow(c, 3)) + (1 + 1. / (2 * b * pow(c, 3)))
                           * sqrt(-M_PI * b * pow(c, 3))* erf(sqrt(-b * pow(c, 3))));
}
