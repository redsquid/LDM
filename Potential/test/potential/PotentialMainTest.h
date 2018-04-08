#ifndef POTENTIALMAINTEST_H
#define POTENTIALMAINTEST_H

#include "utils/test/TestSuite.h"
#include "test/potential/CoulumbEnergySharpTest.h"
#include "test/potential/SurfaceEnergySharpTest.h"
#include "test/potential/RotationEnergyTest.h"
#include "test/potential/PotentialTest.h"
#include "test/potential/SurfacEenergyTest.h"
#include "test/potential/VolumeTest.h"

class PotentialMainTest {
public:
    PotentialMainTest() = delete;

    static void doTest() {
        test::TestSuite suite;
        //suite.registerTest(new SurfaceEnergySharpTest());
        suite.registerTest(new CoulumbEnergySharpTest());
        //suite.registerTest(new RotationEnergyTest());
        //suite.registerTest(new SurfaceEnergyTest());
        //suite.registerTest(new PotentialTest());
        //suite.registerTest(new VolumeTest());
        suite.runTests();
    }

};

#endif // POTENTIALMAINTEST_H
