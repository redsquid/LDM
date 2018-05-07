#ifndef POTENTIALMAINTEST_H
#define POTENTIALMAINTEST_H

#include "utils/test/TestSuite.h"
#include "test/potential/CoulumbEnergySharpTest.h"
#include "test/potential/SurfaceEnergySharpTest.h"
#include "test/potential/RotationEnergySharpTest.h"
#include "test/potential/SurfaceEnergyTest.h"
#include "test/potential/CoulumbEnergyTest.h"
#include "test/potential/RotationEnergyTest.h"
#include "test/potential/PotentialTest.h"
#include "test/potential/VolumeTest.h"

#include "test/potential/FreeEnergyTest.h"

class PotentialMainTest {
public:
    PotentialMainTest() = delete;

    static void doTest() {
        test::TestSuite suite;
        suite.registerTest(new SurfaceEnergySharpTest());
        suite.registerTest(new CoulumbEnergySharpTest());
        suite.registerTest(new RotationEnergySharpTest());

        suite.registerTest(new SurfaceEnergyTest());
        suite.registerTest(new CoulumbEnergyTest());
        suite.registerTest(new RotationEnergyTest());
        suite.registerTest(new VolumeTest());

        suite.registerTest(new FreeEnergyTest());

        //suite.registerTest(new PotentialTest());
        suite.runTests();
    }
};

#endif // POTENTIALMAINTEST_H
