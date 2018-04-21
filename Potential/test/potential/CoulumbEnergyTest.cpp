#include "CoulumbEnergyTest.h"

CoulumbEnergyTest::CoulumbEnergyTest() :
    Test("CoulumbEnergyTest"),
    ce(A, Z)
{
}

CoulumbEnergyTest::~CoulumbEnergyTest() {

}

test::TestResult CoulumbEnergyTest::test() {

    bool result =  doTest(0.50, 0.2, -0.5, -107.085)
                && doTest(0.75, 0.2, -0.5,  -25.407)
                && doTest(1.75, 0.2, -0.5,  -22.890)
                && doTest(2.75, 0.2, -0.5,  -35.271)
                && doTest(3.75, 0.2, -0.5,  -35.447)
                && doTest(4.50, 0.2, -0.5,  -29.704);

    return result ? success() : fail("Wrong surface energy");
}

bool CoulumbEnergyTest::doTest(const double q1, const double q2, const double q3, const double expected) const {
    const Shape shape(q1, q2, q3);
    return fabs(ce(shape) - expected) < EPS;
}
