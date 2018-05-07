#include "VolumeTest.h"

#include "potential/Volume.h"

VolumeTest::VolumeTest() :
    Test("VolumeTest")
{
}

VolumeTest::~VolumeTest() {
}

test::TestResult VolumeTest::test() {
    const double eps = 1e-5;
    const double cmin = 0.5;
    const double cmax = 2.;
    const double dc = 0.1;
    for (double c = cmin; c < cmax; c += dc) {
        Shape s(c, 0, 0);
        if(fabs(Volume::calculate(s) - V0) > eps) {
            return fail("Wrong drop volume");
        }
    }
    return success();
}
