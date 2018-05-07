#include "CoulumbEnergySharpTest.h"

#include "potential/CoulombEnergySharp.h"
#include "potential/Shape.h"

CoulumbEnergySharpTest::CoulumbEnergySharpTest() :
    Test("CoulumbEnergySharpTest"),
    ce(A, Z)
{
}

CoulumbEnergySharpTest::~CoulumbEnergySharpTest() {}

test::TestResult CoulumbEnergySharpTest::test() {

    bool result =  doTest(0.50,  -96.666)
                && doTest(0.75,  -18.720)
                && doTest(1.00,    0.000)
                && doTest(1.50,  -54.722)
                && doTest(2.05, -227.068);

    return result ? success() : fail("Wrong coulumb energy");
}

bool CoulumbEnergySharpTest::doTest(double c, double expected) {
    const Shape shape(c);
    return fabs(ce(shape) - expected) < EPS;
}
