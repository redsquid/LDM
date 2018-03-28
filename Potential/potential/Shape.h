#ifndef SHAPE_H
#define SHAPE_H


class Shape {
public:
    Shape(const double c, const double h, const double alpha);
    virtual ~Shape();
    double operator() (const double z) const;
    double pow2(const double z) const;
    double deriv(const double z) const;
    double getC() const;
    void printShape(const double z1, const double z2, const unsigned int n) const;
    void printDeriv(const double z1, const double z2, const unsigned int n) const;
private:
    double calcShape(const double z) const;
    static double calcB(const double c, const double h);
    static double calcAs(const double c, const double b);
    const double c;
    const double h;
    const double alpha;
    const double b;
    const double as;
};

#endif // SHAPE_H
