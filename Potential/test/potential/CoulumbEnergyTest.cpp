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

    CoulombEnergy se(4, 2);
    const double expected = se.ec0();
    Shape shape(1., 0., 0.);
    double res = se(shape);

    return fabs(res - expected) > eps ?
                fail("Coulumb energy for spherical shape: expected: " + std::to_string(se.ec0()) +
                     "actual: " + std::to_string(res))
              : success();
}
