#include "SurfacEenergyTest.h"

#include "potential/SurfaceEnerge.h"

SurfaceEnergyTest::SurfaceEnergyTest() :
    Test("SurfaceEnergyTest")
{
}

SurfaceEnergyTest::~SurfaceEnergyTest() {

}

test::TestResult SurfaceEnergyTest::test() {

    SurfaceEnerge se();

    return fail("Test is not implemented");
}
