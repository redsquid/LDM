#ifndef RANDOM_H
#define RANDOM_H

#include "IRandom.h"

#include <random>

class Random : public IRandom {
public:
	Random(double stddev);
	Random(double mean, double stddev);
	virtual ~Random();
	double next();

private:
	std::mt19937 gen;
	std::normal_distribution<double> dist;
};

#endif //RANDOM_H
