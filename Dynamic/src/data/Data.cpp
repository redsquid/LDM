#include "data/Data.h"
#include "potential/PotentialLoader.h"
#include "utils/logger/Logger.h"
#include "potential/PotentialLoaderException.h"

const Potential Data::potential = initPotential();

const IPotential& Data::getPotential() {
	return potential;
}

Potential Data::initPotential() {
	Logger::print("Loading potential...");
	PotentialLoader loader;
	try {
		Potential p = loader.load();
		Logger::ok();
	
		//for(double q = 0.1; q <1.0; q += 0.1) {
		//	std::cout << p.value(q) << std::endl;		
		//}

		return p;

	} catch(PotentialLoaderException e) {
		Logger::error(e.message());
	}

	exit(1);
}

