#ifndef CSHAPEFACTORY_H
#define CSHAPEFACTORY_H

#include "IShapeFactory.h"

class CShapeFactory : public IShapeFactory {
public:
	CShapeFactory(double h, double a) : h_(h), a_(a) {}

	Shape get(double value) override {
		return Shape(Coordinates::cha(value, h_, a_));
	}

private:
	const double h_;
	const double a_;

};

#endif //CSHAPEFACTORY_H


