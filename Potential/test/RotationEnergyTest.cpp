#include "RotationEnergyTest.h"

#include "potential/RotationEnergy.h"
#include <iostream>

RotationEnergyTest::RotationEnergyTest() :
    Test("RotationEnergyTest")
{
}

RotationEnergyTest::~RotationEnergyTest() {

}

test::TestResult RotationEnergyTest::test() {


    double vI = 0;
    double vK = 1;
    RotationEnergy re(4);

    const double expected = 0;
    Shape shape(1.5, 0., 0.);
    double res = re(shape, vI, vK);

    std::cout << res << std::endl;

    return fail("Test is not implemented");

}
