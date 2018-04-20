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




double int_As(double c, double h) {
    double B;
    B = 2. * h + 0.5 * (c - 1.);
    if (fabs(B) < 1.e-5)
        B = 0;
    if (B >= 0)
        return (1. / (c * c * c) - 0.2 * B);
    else
        return (2.0 / 3.0 / (sqrt(M_PI) * erf(c * sqrt(-B * c)) * c * c * c * B
        / 2 - exp(c * c * c * B) * c * sqrt(-B * c) / 2 + sqrt(M_PI)
        * erf(c * sqrt(-B * c)) / 4) * B * c * sqrt(-B * c));
}


double Shape::deriv2(const double z) const {
    double B, As;
    B = 2. * h_ + 0.5 * (c_ - 1.);
    As = int_As(c_, h_);
    if (fabs(B) < 1e-3)
        B = 0;
    if (B >= 0) {
        double t1, t3, t4, t7;
        t1 = z * z;
        t3 = c_ * c_;
        t4 = 1 / t3;
        t7 = 1 / c_;
        return (-2.0 * z * (As + B * t1 * t4 + a_ * z * t7) + (t3 - t1) * (2.0
            * B * z * t4 + a_ * t7));
    } else {
        double t12, t13, t9, t7, t2, t4;
        t2 = 1 / c_;
        t4 = As + a_ * z * t2;
        t7 = z * z;
        t9 = exp(B * c_ * t7);
        t12 = c_ * c_;
        t13 = t12 - t7;
        return (-2.0 * z * t4 * t9 + t13 * a_ * t2 * t9 + 2.0 * t13 * t4 * B * c_
            * z * t9);
    }
}

double Shape::zcm() const {
    double B;
    B = 2. * h_ + 0.5 * (c_ - 1.);
    if (fabs(B) < 1e-3)
        B = 0;
    if (B >= 0)
        return (0.2 * a_ * c_ * c_ * c_ * c_);
    else {
        double t1, t3, t5, t6, t7, t8, t9, t12, t20, t27;
        t1 = sqrt(0.3141592653589793E1);
        t3 = sqrt(-B * c_);
        t5 = erf(c_ * t3);
        t6 = t1 * t5;
        t7 = c_ * c_;
        t8 = t7 * c_;
        t9 = t8 * B;
        t12 = exp(t9);
        t20 = B * B;
        t27 = -3.0 / 16.0 * a_ * (2.0 * t6 * t9 - 6.0 * t12 * c_ * t3 + 3.0 * t6)
            / t8 / t20 / t3;
        return (t27);
    }
}


