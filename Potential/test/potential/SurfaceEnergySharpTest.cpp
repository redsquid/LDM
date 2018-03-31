#include "SurfaceEnergySharpTest.h"

#include "potential/Shape.h"
#include "potential/SurfaceEnergySharp.h"

#include <iostream>
#include <math.h>
#include <string>

SurfaceEnergySharpTest::SurfaceEnergySharpTest() :
    Test("SurfaceEnergyTest")
{
}

SurfaceEnergySharpTest::~SurfaceEnergySharpTest() {}

test::TestResult SurfaceEnergySharpTest::test() {
    const double eps = 1e-10;

    SurfaceEnergySharp se(4, 2);
    const double expected = se.es0();
    Shape shape(1., 0., 0.);
    double res = se(shape);
    return fabs(res - expected) > eps ?
                fail("Surface energy for spherical shape: expected: " + std::to_string(se.es0()) +
                     " actual: " + std::to_string(res))
              : success();
}
