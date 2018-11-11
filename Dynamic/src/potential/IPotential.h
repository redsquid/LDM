#ifndef IPOTENTIAL_H
#define IPOTENTIAL_H

class IPotential {
public:
	virtual ~IPotential() {}

	virtual double value(double q1, double q2 = 0, double q3 = 0) const = 0;

	/**
	 *   i,j = 0, 1, 2 (0 - q1, 1 - q2, 2 - q3)
	 */
	//static double get(uint i, uint j, double q1, double q2, double q3);



};

#endif //IPOTENTIAL_H
