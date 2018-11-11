#include "Random.h"
#include <chrono>

Random::Random(double stddev) :
	gen(std::chrono::system_clock::now().time_since_epoch().count()),
	dist(0, stddev)
{
}

Random::Random(double mean, double stddev) :
	dist(mean, stddev)
{
}

Random::~Random() {
}

double Random::next() {
	return dist(gen);
}

