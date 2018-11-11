#ifndef POTENTIAL_H
#define POTENTIAL_H

#include "IPotential.h"
#include <vector>

class Potential : public IPotential {
public:
	Potential(std::vector<double> data, double qmin, double qmax);
	virtual ~Potential();

	double value(double q1, double q2 = 0, double q3 = 0) const override;
	double qmin() const;
	double qmax() const;
private:
	const std::vector<double> data_;
	const double qmin_;
	const double qmax_;
	const double dq_;
};

#endif //POTENTIAL_H
