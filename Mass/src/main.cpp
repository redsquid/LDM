#include "mass/Mass.h"
#include <iostream>


void masscc() {
	

	unsigned int A = 10;

	Mass mass(A);

	double cmin = 0.5;
	double cmax = 2.1;
	int n = 20;

	double dc = 0.05; 
	
	for (double c = cmin; c <= cmax; c +=dc) {
		std::cout << c << "\t"  << mass.cc(c, 0, 0) << std::endl;
	}
}

void masscc1() {

	int n = 10;
	double c = 1.;
	A ac = A::createAc(c, 0, 0);
	Mass mass(10);

	double zmin = -c;
	double zmax = c;
	double dz = (zmax - zmin) / n;


	CShapeFactory factory(0, 0);

	for(double z = zmin; z <= zmax; z += dz) {
	
		std::cout << z << " " << ac(z) << " " << mass.aa1(z, c, &factory) << std::endl;

	}
}


int main() {

//	std::cout << "-----df / dc-----" << std::endl;
//	shape_dc();
	
//	std::cout << "-----df / dh-----" << std::endl;
//	shape_dh();

	masscc();


	return 0;

}
