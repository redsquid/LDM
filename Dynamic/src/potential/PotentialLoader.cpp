#include "PotentialLoader.h"
#include "Potential.h"
#include <fstream>
#include "PotentialLoaderException.h"

PotentialLoader::PotentialLoader() {
}

PotentialLoader::~PotentialLoader() {
}

Potential PotentialLoader::load() {
	std::ifstream file("data/potential.txt", std::ios::in);
	
	if(file.fail()) {
		throw PotentialLoaderException("Can't read file");
	}

	int n;
	file >> n;
	std::vector<double> data(n);

	double qmin;
	file >> qmin;

	double qmax;
	file >> qmax;

	for(int i = 0; i < n; i++) {
		double value;
		file >> value;
		data[i] = value;
	}

	double value;
	file >> value;

	if(!file.eof()) {
		throw PotentialLoaderException("Wrong file format");
	}

	file.close();
	
	return Potential(data, qmin, qmax);
}

