#ifndef ISHAPEFACTORY_H
#define ISHAPEFACTORY_H

#include "../Shape.h"

class IShapeFactory {
public:
	virtual ~IShapeFactory() {}
	virtual Shape get(double coordinate) = 0;
};

#endif //ISHAPEFACTORY_H


