#ifndef HSHAPEFACTORY_H
#define HSHAPEFACTORY_H

#include "IShapeFactory.h"

class HShapeFactory : public IShapeFactory {
public:
	HShapeFactory(double c, double a) : c_(c), a_(a) {}

	Shape get(double value) override {
		return Shape(Coordinates::cha(c_, value, a_));
	}

private:
	const double c_;
	const double a_;

};

#endif //HSHAPEFACTORY_H


