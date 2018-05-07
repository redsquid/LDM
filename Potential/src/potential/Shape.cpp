#include "Shape.h"

#include <gsl/gsl_math.h>

Shape::Shape(const double q1, const double q2, const double q3) :
    c_(q1),
    h_(q2 * (5. / (2 * pow(c_, 3)) + (1 - c_) / 4) + 3. / 2 * (q2 - 1)),
    b_(calcB(c_, h_)),
    as_(calcAs(c_, b_)),
    a_(b_ >= 0 ? q3 * (as_ + b_) : q3 * as_)
{
}

Shape::Shape(const double c) :
    c_(c),
    h_(0),
    b_(calcB(c_, h_)),
    as_(calcAs(c_, b_)),
    a_(0)
{
}

Shape::Shape(const Coordinates::CHA coordinates) :
	c_(coordinates.c()),
	h_(coordinates.h()),
	b_(calcB(c_, h_)),
    as_(calcAs(c_, b_)),
	a_(coordinates.a())
{
}

Shape::Shape(const Shape& shape) :
    c_(shape.c_),
    h_(shape.h_),
    b_(shape.b_),
    as_(shape.as_),
    a_(shape.a_)
{
}

Shape::~Shape() {}

double Shape::operator() (const double z) const {
    return sqrt(pow2(z));
}

double Shape::value(const double z) const {
    return sqrt(pow2(z));
}

double Shape::pow2(const double z) const {
    double result = (b_ >= 0) ? (pow(c_, 2) - pow(z, 2)) * (as_ + b_ * pow(z, 2) / pow(c_, 2) + a_ * z / c_) :
                               (pow(c_, 2) - pow(z, 2)) * (as_ + a_ * z / c_) * exp(b_ * c_ * pow(z, 2));
    return (result < 0) ? 0 : result;
}

double Shape::deriv(const double _z) const {
    const double dz = 1e-6;
    double z = ((fabs(c_) - fabs(_z)) < dz) ? _z - GSL_SIGN(_z) * dz : _z;
    return (this->operator ()(z + dz) - this->operator ()(z - dz)) / (2 * dz);
}

double Shape::zmin() const {
    return -c_;
}

double Shape::zmax() const {
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

double Shape::zcm() const {
    if (b_ >= 0) {
        return 1. / 5 * a_ * pow(c_, 4);
    } else {
        double tmp0 = sqrt(M_PI) * erf(c_ * sqrt(-b_ * c_));
        double tmp1 = b_ * pow(c_, 3);
        return -3. / 16 * a_ * (2 * tmp0 * tmp1 - 6 * exp(tmp1) * c_ * sqrt(-b_ * c_) + 3 * tmp0)
            / pow(c_, 3) / pow(b_, 2) / sqrt(-b_ * c_);
    }
}


