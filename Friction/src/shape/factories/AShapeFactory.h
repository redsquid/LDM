#ifndef ASHAPEFACTORY_H
#define ASHAPEFACTORY_H

#include "IShapeFactory.h"

class AShapeFactory : public IShapeFactory {
public:
	AShapeFactory(double c, double h) : c_(c), h_(h) {}

	Shape get(double value) override {
		return Shape(Coordinates::cha(c_, h_, value));
	}

private:
	const double c_;
	const double h_;

};

#endif //ASHAPEFACTORY_H


