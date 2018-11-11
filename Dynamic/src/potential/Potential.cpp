#include "Potential.h"
#include <cmath>

Potential::Potential(std::vector<double> data, double qmin, double qmax) : 
	data_(data),
	qmin_(qmin),
	qmax_(qmax),	
	dq_((qmax - qmin) / (data.size() - 1))
{
}

Potential::~Potential() {
}

double Potential::qmin() const {
	return qmin_;	
}

double Potential::qmax() const {
	return qmax_;
}

double Potential::value(double q1, double q2, double q3) const {
	return data_[(int) round((q1 - qmin_) / dq_)];
}

