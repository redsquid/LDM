#include "Mass.h"
#include "gauss/GaussTable.h"

#include <gsl/gsl_integration.h>

#include <iostream>

#include <gsl/gsl_deriv.h>


#include "shape/factories/CShapeFactory.h"

struct Params {
	A* a1;
	A* a2;
	Shape* shape;
};


struct ShapeParams {
	IShapeFactory* factory;
	double arg;
};

Mass::Mass(uint A) :
	A_(A)
{

}

Mass::~Mass() {
}

double Mass::cc(const double c, const double h, const double a) const {

	Shape shape(Coordinates::cha(c, h, a));

	A ac = A::createAc(c, h, a);
	


	return compute(shape, ac, ac);
}

	

double Mass::compute(Shape& shape, A& a1, A& a2) const {
	
	Params p = {.a1 = &a1, .a2 = &a2, .shape = &shape};
	const gsl_function function = {.function = integrand, .params = &p};
	return gsl_integration_glfixed(&function, shape.zmin(), shape.zmax(), GaussTable::get());
}


double Mass::integrand(double z, void* params) {

	Params* p = static_cast<Params*>(params);
	A& a1 = *(p->a1);
	A& a2 = *(p->a2);
	Shape& shape = *(p->shape);


	return   3. / 4 * shape.pow2(z) * (a1(z) * a2(z) + shape.pow2(z) / 8 * a1.bydz(z) * a2.bydz(z));

/*
	double c = shape.zmax();
	
	double dz = 1e-3;	

	//double dccdz = (cc1(dpdz, c, 0, 0) - cc1(dmdz, c, 0, 0)) / (2 * dz); 


	CShapeFactory cfactory(0, 0);	



	ShapeParams p1 = {.factory = &cfactory, .arg = c};
	const gsl_function function = {.function = derivcc1, .params = &p1};
	
	double dcc1dz;
	double abserr;
	
	
	if (z < -c + dz) {
		gsl_deriv_forward(&function, z, dz, &dcc1dz, &abserr);
	} else if (z > c - dz) {
		gsl_deriv_backward(&function, z, dz, &dcc1dz, &abserr);
	} else {

		int n  = gsl_deriv_central(&function, z, dz, &dcc1dz, &abserr); 
	}	
	
		return 3. / 4 * shape.pow2(z) * (a1(z, c, &cfactory) * a1(z, c, &cfactory) + shape.pow2(z) / 8 * dcc1dz * dcc1dz);
*/
		
}



double Mass::derivcc1(double z, void* param) {
	ShapeParams* p = static_cast<ShapeParams*>(param);
	return aa1(z, p->arg, p->factory);
}

double Mass::aa1(double z, double value, IShapeFactory* factory) {

	ShapeParams params = {.factory = factory, .arg = z};
	const gsl_function function = {.function = fint1, .params = &params};
	
	double result;
	double abserr;
	
	gsl_deriv_central(&function, value, 1e-3, &result, &abserr); 

	double ro2 = factory->get(value).pow2(z);
	ro2 = (ro2 < 1e-6) ? 1e-6 : ro2;

	return -1. / ro2 * result;
}


double Mass::fint1(double value, void* param) {
	ShapeParams* params = static_cast<ShapeParams*>(param);
	Shape shape = params->factory->get(value);
	const gsl_function function = {.function = integrand1, .params = &shape};
	return gsl_integration_glfixed(&function, -value, params->arg, GaussTable::get());
}


double Mass::integrand1(double z, void* params) {
	Shape& shape = *(static_cast<Shape*>(params));
	return shape.pow2(z);
}

