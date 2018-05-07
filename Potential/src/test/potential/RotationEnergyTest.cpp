#include "RotationEnergyTest.h"

RotationEnergyTest::RotationEnergyTest() :
    Test("RotationEnergyTest"),
    re(A, Z)
{
}

RotationEnergyTest::~RotationEnergyTest() {

}

test::TestResult RotationEnergyTest::test() {

    bool result =  doTest(0.50, 0.2, -0.5, 0.100)
                && doTest(0.75, 0.2, -0.5, 0.123)
                && doTest(1.75, 0.2, -0.5, 0.123)
                && doTest(2.75, 0.2, -0.5, 0.119)
                && doTest(3.75, 0.2, -0.5, 0.119)
                && doTest(4.50, 0.2, -0.5, 0.121);

    return result ? success() : fail("Wrong surface energy");
}

bool RotationEnergyTest::doTest(const double q1, const double q2, const double q3, const double expected) const {
    const Shape shape(q1, q2, q3);
    return fabs(re(shape, L, K) - expected) < EPS;
}
