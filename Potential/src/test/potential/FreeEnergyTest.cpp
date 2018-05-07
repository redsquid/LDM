#include "FreeEnergyTest.h"

#include <iostream>
#include <fstream>
#include "potential/Coordinates.h"

FreeEnergyTest::FreeEnergyTest() :
    Test("FreeEnergyTest")
{
}

FreeEnergyTest::~FreeEnergyTest() {

}

test::TestResult FreeEnergyTest::test() {

    std::ofstream out;
    out.open("out.txt");

    FreeEnergy freeEn(214, 86, 1.5);

    double e = 0;
/*
    out << 0 << " ";
    for(double c = 0.8; c <= 2.05; c += 0.05) {
        out << c << " ";
    }
    for (double k = -40; k <= 40; k+=2) {
        out << std::endl << k << " ";
        for(double c = 0.8; c <= 2.05; c += 0.05) {
            Shape shape(c);
            e = freeEn(shape, 40, k);
            out << e << " ";
        }
        std::cout << k << std::endl;
    }
*/

/*	out << 0 << " ";
	for(double c = 0.8; c <= 2.21; c += 0.1) {
        out << c << " ";
    }

    for (double a = -1.0; a <= 1.01; a += 0.05) {
        out << std::endl << a << " ";
        for(double c  = 0.8; c <= 2.21; c += 0.1) {
            Shape shape(Coordinates::cha(c, 0, a));
            out << freeEn(shape, 0, 0) << " ";
        }
        std::cout << a << std::endl;
    }
*/


    return fail("Test is not implemented");
}
