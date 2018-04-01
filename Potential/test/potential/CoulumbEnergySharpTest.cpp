#include "CoulumbEnergySharpTest.h"

#include "potential/CoulombEnergySharp.h"
#include "potential/Shape.h"

#include <iostream>

CoulumbEnergySharpTest::CoulumbEnergySharpTest() :
    Test("CoulumbEnergySharpTest")
{
}

CoulumbEnergySharpTest::~CoulumbEnergySharpTest() {}

test::TestResult CoulumbEnergySharpTest::test() {

    const double eps = 1e-10;

    CoulombEnergySharp se(4, 2);
    const double expected = se.ec0();
    Shape shape(1., 0., 0.);
    double res = se(shape);

    return fabs(res - expected) > eps ?
                fail("Coulumb energy for spherical shape: expected: " + std::to_string(se.ec0()) +
                     "actual: " + std::to_string(res))
              : success();
}
