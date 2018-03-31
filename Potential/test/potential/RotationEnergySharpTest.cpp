#include "RotationEnergySharpTest.h"

#include "potential/RotationEnergySharp.h"
#include <iostream>

RotationEnergySharpTest::RotationEnergySharpTest() :
    Test("RotationEnergySharpTest")
{
}

RotationEnergySharpTest::~RotationEnergySharpTest() {

}

test::TestResult RotationEnergySharpTest::test() {


    double vI = 0;
    double vK = 1;
    RotationEnergySharp re(4);

    const double expected = 0;
    Shape shape(1.5, 0., 0.);
    double res = re(shape, vI, vK);

    std::cout << res << std::endl;

    return fail("Test is not implemented");

}
