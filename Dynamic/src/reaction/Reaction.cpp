#include "Reaction.h"
#include <cstdlib>
#include <iostream>

Reaction::Reaction(const Nucleus& p, const Nucleus& t) :
rnd(DEV)
{
}

Reaction::~Reaction() {

}




Result Reaction::compute() {
	
	const uint N = 10000;

	const uint M = 200;
    const double tmax = 10;	
	const double dt = tmax / M;
	const double gamma = 200; //MeV / sec
	const double m = 200; //MeV
	const double T = 2; //MeV

	const double k = 1;

	const double pinit = 0.;
	const double qinit = 0;

	double p;
	double q;

	double pres[M] = {0};
	double qres[M] = {0};

	for(uint i = 0; i < N; i++) {
		
		double p0 = pinit;
	    double q0 = qinit;

		for(uint j = 0; j < M; j++) {


			q = q0 + dt * p0 / m;
			p = p0 * (1. - dt * gamma / m) + sqrt(T * gamma * dt) * rnd.next();
			
			pres[j] += p * p;
			qres[j] += q * q;

			p0 = p;
			q0 = q;
		}
	}

	for(uint i = 0; i < M; i++) {
		pres[i] /= N;
		qres[i] /= N;

		//std::cout << i * dt << "     " << pres[i]  << std::endl;
		std::cout << i * dt << " " << qres[i] << std::endl; //"    " << 2. *  k * T / gamma * i * dt << std::endl;
	}

	return Result();
}


