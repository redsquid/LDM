#include "RotationEnergySharpTest.h"

#include "potential/RotationEnergySharp.h"
#include <iostream>

RotationEnergySharpTest::RotationEnergySharpTest() :
    Test("RotationEnergySharpTest"),
    re(A)
{
}

RotationEnergySharpTest::~RotationEnergySharpTest() {
}

test::TestResult RotationEnergySharpTest::test() {

    bool result =  doTest(0.50, 0.098)
                && doTest(0.75, 0.121)
                && doTest(1.00, 0.124)
                && doTest(1.50, 0.106)
                && doTest(2.05, 0.078);

    return result ? success() : fail("Wrong rotation energy");
}

bool RotationEnergySharpTest::doTest(double c, double expected) const {
    const Shape shape(c);
    return fabs(re(shape, L, K) - expected) < EPS;
}
