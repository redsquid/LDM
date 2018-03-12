#include "Shape.h"
#include "utils/logger/Logger.h"
#include <cmath>
#include <vector>
#include <gsl/gsl_math.h>

Shape::Shape(const double _c, const double _h, const double _alpha) :
    c(_c),
    h(_h),
    alpha(_alpha),
    b(calcB(c, h)),
    as(calcAs(c, b))
{
}

Shape::~Shape() {}

double Shape::operator() (const double z) const {
    return sqrt(calcShape(z));
}

double Shape::pow2(const double z) const {
    return calcShape(z);
}

double Shape::calcShape(const double z) const {

    double result = (b >= 0) ? (pow(c, 2) - pow(z, 2)) * (as + b * pow(z, 2) / pow(c, 2) + alpha * z / c) :
                               (pow(c, 2) - pow(z, 2)) * (as + alpha * z / c) * exp(b * c * pow(c, 2));

    return (result < 0) ? 0 : result;
}

double Shape::deriv(const double _z) const {

    const double eps = 1e-15;

    const double z = ((fabs(_z) - c) < eps || _z < eps) ? _z - GSL_SIGN(_z) * eps : _z;

    if(b >= 0) {
        const double tmp = (pow(c, 2) - pow(z, 2)) * (as + b * pow(z, 2) / pow(c, 2) + alpha * z / pow(c, 4));
        return tmp <= 0 ? 0 :
            (2 * z * (b - as) - 4 * b * pow(z, 3) / pow(c, 2) - 3 * alpha * pow(z, 2) / pow(c, 4) + alpha / pow(c, 2))
                          / (2 * sqrt(tmp));
    } else {

        const double tmp = (pow(c, 2) - pow(z, 2))  * (as + alpha * z / pow(c, 4)) * exp(b * c * pow(z, 2));
        return tmp <= 0 ? 0 :
            (alpha / pow(c, 2) - 2 * alpha * b * pow(z, 4) / pow(c, 3) - 2 * b * as * c * pow(z, 3)
            + (2 * b * pow(c, 3) - 3) * alpha * pow(z, 2) / pow(c, 4) + 2 * (b * pow(c, 3) - 1) * as * z)
                          / (2 * sqrt(tmp));
    }
}

double Shape::getC() const {
    return c;
}

double Shape::calcB(const double c, const double h) {

    return 2 * h + (c - 1) / 2.;
}

double Shape::calcAs(const double c, const double b) {

    if (b >= 0) {
        return pow(c, -3) - b / 5.;
    } else {
        return -4 / 3. * b / (exp(b * pow(c, 3)) + (1 + 1 / (2 * b * pow(c, 3))) * sqrt(-M_PI * b * pow(c, 3))
                              * erf(sqrt(-b * pow(c, 3))));
    }
}

void Shape::printShape(const double z1, const double z2, const unsigned int n) const {

    const logger::Logger logger("Shape");
    const double dz = (z2 - z1) / n;

    for(unsigned int i = 0; i <= n; i++) {
        logger.print(this->operator ()(z1 + i * dz));
    }
}

void Shape::printDeriv(const double z1, const double z2, const unsigned int n) const {

    const logger::Logger logger("dShape / dz");
    const double dz = (z2 - z1) / n;

    for(unsigned int i = 0; i < n; i++) {
        logger.print(this->deriv(z1 + i * dz + dz / 2.));
    }
}

