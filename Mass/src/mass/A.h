#ifndef A_H
#define A_H

#include "shape/factories/IShapeFactory.h"
#include "shape/factories/CShapeFactory.h"
#include "gauss/GaussTable.h"

#include <gsl/gsl_deriv.h>
#include <gsl/gsl_integration.h>

class A {
public:

	A(double s, IShapeFactory* factory) : s_(s), factory_(factory) {}

	virtual ~A() {
		delete factory_;
	}

	static A createAc(double c, double h, double a) {
		return A(c, new CShapeFactory(h, a));	

	}


	double operator()(const double z) const {
		return a1(z, s_, factory_);
	}
	
	double bydz(const double z) const {
		ShapeParams p = {.factory = factory_, .arg = s_};
		const gsl_function function = {.function = derivcc1, .params = &p};
	
		double dcc1dz;
		double abserr;

		const double c = factory_->get(s_).zmax();
		const double dz = 1e-3;	
	
		if (z < -c + dz) {
			gsl_deriv_forward(&function, z, dz, &dcc1dz, &abserr);
		} else if (z > c - dz) {
			gsl_deriv_backward(&function, z, dz, &dcc1dz, &abserr);
		} else {

			gsl_deriv_central(&function, z, dz, &dcc1dz, &abserr); 
		}	
		
		return dcc1dz;	
	}


private:
	
	const double s_;

	IShapeFactory* factory_;

struct ShapeParams {
	IShapeFactory* factory;
	double arg;
};


static double derivcc1(double z, void* param) {
	ShapeParams* p = static_cast<ShapeParams*>(param);
	return a1(z, p->arg, p->factory);
}



	static double a1(double z, double value, IShapeFactory* factory) {

	ShapeParams params = {.factory = factory, .arg = z};
	const gsl_function function = {.function = fint1, .params = &params};
	
	double result;
	double abserr;
	
	gsl_deriv_central(&function, value, 1e-3, &result, &abserr); 

	double ro2 = factory->get(value).pow2(z);
	ro2 = (ro2 < 1e-6) ? 1e-6 : ro2;

	return -1. / ro2 * result;
}


static double fint1(double value, void* param) {
	ShapeParams* params = static_cast<ShapeParams*>(param);
	Shape shape = params->factory->get(value);
	const gsl_function function = {.function = integrand1, .params = &shape};
	return gsl_integration_glfixed(&function, -value, params->arg, GaussTable::get());
}


static double integrand1(double z, void* params) {
	Shape& shape = *(static_cast<Shape*>(params));
	return shape.pow2(z);
}



};

#endif //A_H
