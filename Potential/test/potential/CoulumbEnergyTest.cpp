#include "CoulumbEnergyTest.h"

CoulumbEnergyTest::CoulumbEnergyTest() :
    Test("CoulumbEnergyTest"),
    ce(A, Z)
{
}

CoulumbEnergyTest::~CoulumbEnergyTest() {

}

test::TestResult CoulumbEnergyTest::test() {

//    bool result =  doTest(0.50, 0.2, -0.5, 165.201)
//                && doTest(0.75, 0.2, -0.5,  34.662)
//                && doTest(1.75, 0.2, -0.5,  43.538)
//                && doTest(2.75, 0.2, -0.5,  67.437)
//                && doTest(3.75, 0.2, -0.5,  93.116)
//                && doTest(4.50, 0.2, -0.5, 108.420);

    //return result ? success() : fail("Wrong surface energy");

    return fail("Test is not implemented");
}

bool CoulumbEnergyTest::doTest(const double q1, const double q2, const double q3, const double expected) const {
    const Shape shape(q1, q2, q3);
    return fabs(ce(shape) - expected) < EPS;
}
