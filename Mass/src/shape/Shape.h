#ifndef SHAPE_H
#define SHAPE_H

#include <math.h>

#include "Coordinates.h"

class Shape {
public:
    // {q1, q2, q3} q1 - [0.5; 4.5] q2 - [0; 1] q3 - [-1; 1]
    Shape(const double q1, const double q2, const double q3);
    // {c, h = 0, a = 0}
    Shape(const double c);
    Shape(const Coordinates::CHA coordinates);
	Shape(const Shape& shape);
    virtual ~Shape();
    double operator() (const double z) const;
//    double value(const double z) const;
    double pow2(const double z) const;
    double deriv(const double z) const;
    double zmin() const;
    double zmax() const;
    double zcm() const;

//	double ac(const double z) const;
//	double ah(const double z) const;
//	double aa(const double z) const;
private:
//    double calcShape(const double z) const;
    static double calcB(const double c, const double h);
    static double calcAs(const double c, const double b);

    const double c_;
    const double h_;
    const double b_;
    const double as_;
    const double a_;
};

#endif // SHAPE_H
