#ifndef SHAPE_H
#define SHAPE_H

#include <math.h>

class Shape {
public:
    Shape(const double c, const double h, const double a);
    virtual ~Shape();
    double operator() (const double z) const;
    double pow2(const double z) const;
    double deriv(const double z) const;
    double getC() const;

private:
    double calcShape(const double z) const;
    static double calcB(const double c, const double h);
    static double calcAs(const double c, const double b);

    const double c_;
    const double h_;
    const double a_;
    const double b_;
    const double as_;

};

#endif // SHAPE_H
