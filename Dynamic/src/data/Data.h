#ifndef DATA_H
#define DATA_H

//#include "potential/IPotential.h"
#include "potential/Potential.h"

class Data {
public:
	Data() = delete;
	~Data() = delete;

	static const IPotential& getPotential();


private:
	static Potential initPotential();

	static const Potential potential;

};

#endif //DATA_H



