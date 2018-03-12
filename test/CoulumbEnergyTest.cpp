#include "CoulumbEnergyTest.h"

#include "potential/CoulombEnergy.h"
#include "potential/Shape.h"

#include <iostream>

CoulumbEnergyTest::CoulumbEnergyTest() :
Test("CoulombEnergyTest")
{
}

CoulumbEnergyTest::~CoulumbEnergyTest() {}

test::TestResult CoulumbEnergyTest::test() {

    const double eps = 1e-10;

    const double expected = 0;
    Shape shape(1, 0., 0.);
    CoulombEnergy ce(4, 2);

    double res = ce(shape);

    std::cout << "Result: " << res << std::endl;

    return fail("Test not implemented");
}
