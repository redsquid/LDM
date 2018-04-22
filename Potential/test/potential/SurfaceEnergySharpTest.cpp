#include "SurfaceEnergySharpTest.h"

#include "potential/Shape.h"

SurfaceEnergySharpTest::SurfaceEnergySharpTest() :
    Test("SurfaceEnergySharpTest"),
    se(A, Z)
{
}

SurfaceEnergySharpTest::~SurfaceEnergySharpTest() {}

test::TestResult SurfaceEnergySharpTest::test() {

    bool result =  doTest(0.50, 152.694)
                && doTest(0.75,  24.716)
                && doTest(1.00,  00.000)
                && doTest(1.50,  55.889)
                && doTest(2.05, 200.453);

    return result ? success() : fail("Wrong surface energy");
}

bool SurfaceEnergySharpTest::doTest(double c, double expected) {
    const Shape shape(c);
    return fabs(se(shape) - expected) < EPS;
}
