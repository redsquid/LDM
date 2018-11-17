#ifndef MASS_H
#define MASS_H

#include <cstdlib>

#include "A.h"
#include "Shape.h"
#include "factories/IShapeFactory.h"

class Mass {
public:
	Mass(uint A);
	virtual ~Mass();
	
	
    double operator ()(const double c, const double h, const double a) const;

	
	double cc(const double c, const double h, const double a) const;
	double hh(const double c, const double h, const double a) const;
	double aa(const double c, const double h, const double a) const;
	double ch(const double c, const double h, const double a) const;
	double ca(const double c, const double h, const double a) const;
	double ha(const double c, const double h, const double a) const;


	static double derivcc1(double z, void* param);
	static double aa1(double z, double value, IShapeFactory* factory);
	
	static double fint1(double z, void* param);
	static double integrand1(double z, void* params);
private:
	const uint A_;
	
	double compute(Shape& shape, A& a1, A& a2) const;
	static double integrand(double z, void* params);

};

#endif //MASS_H
