#ifndef A_H
#define A_H

#include "factories/IShapeFactory.h"
#include "factories/CShapeFactory.h"
#include "gauss/GaussTable.h"

#include <gsl/gsl_deriv.h>
#include <gsl/gsl_integration.h>

class A {
public:
	A(double s, IShapeFactory* factory);
	virtual ~A();
   
	static A createAc(double c, double h, double a) ;
	double operator()(const double z) const;
	double bydz(const double z) const;

private:
	struct ShapeParams;

	const double s_;
	IShapeFactory* factory_;
	
	static double derivcc1(double z, void* param);
	static double a1(double z, double value, IShapeFactory* factory);
	
	static double fint1(double value, void* param);
	static double integrand1(double z, void* params);
};

#endif //A_H

