#include "SurfaceEnergyTest.h"

#include "potential/Shape.h"
#include "potential/SurfaceEnergy.h"

#include <iostream>
#include <math.h>
#include <string>

SurfaceEnergyTest::SurfaceEnergyTest() :
    Test("SurfaceEnergyTest")
{
}

SurfaceEnergyTest::~SurfaceEnergyTest() {}

test::TestResult SurfaceEnergyTest::test() {
    const double eps = 1e-10;

    SurfaceEnergy se(4, 2);
    const double expected = se.es0();
    Shape shape(1., 0., 0.);
    double res = se(shape);
    return fabs(res - expected) > eps ?
                fail("Surface energy for spherical shape: expected: " + std::to_string(se.es0()) +
                     " actual: " + std::to_string(res))
              : success();
}
