#include "CoulumbEnergySharpTest.h"

#include "potential/CoulombEnergySharp.h"
#include "potential/Shape.h"

CoulumbEnergySharpTest::CoulumbEnergySharpTest() :
    Test("CoulumbEnergySharpTest")
{
}

CoulumbEnergySharpTest::~CoulumbEnergySharpTest() {}

test::TestResult CoulumbEnergySharpTest::test() {

    const double eps = 1;

    CoulombEnergySharp se(252, 100);

    const double e1 = -96.6656; //0.5
    const double e2 = -9.17679; //1.2
    const double e3 = -211.291; //2

    Shape s1(0.5, 0., 0.);
    Shape s2(1.2, 0., 0.);
    Shape s3(2.0, 0., 0.);

    return ((fabs(se(s1) - se.ec0() - e1) > eps) ||
            (fabs(se(s2) - se.ec0() - e2) > eps) ||
            (fabs(se(s3) - se.ec0() - e3) > eps)) ?
                fail("Wrong coulumb energy") : success();
}
