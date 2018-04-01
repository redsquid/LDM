#ifndef POTENTIALMAINTEST_H
#define POTENTIALMAINTEST_H

#include "utils/test/TestSuite.h"
#include "test/potential/CoulumbEnergySharpTest.h"
#include "test/potential/SurfaceEnergySharpTest.h"
#include "test/potential/RotationEnergySharpTest.h"
#include "test/potential/PotentialSharpTest.h"
#include "test/potential/SurfacEenergyTest.h"

class PotentialMainTest {
public:
    PotentialMainTest() = delete;

    static void doTest() {
        test::TestSuite suite;
        suite.registerTest(new SurfaceEnergySharpTest());
        suite.registerTest(new CoulumbEnergySharpTest());
        suite.registerTest(new RotationEnergySharpTest());
        suite.registerTest(new PotentialSharpTest());
        suite.registerTest(new SurfaceEnergyTest());
        suite.runTests();
    }

};

#endif // POTENTIALMAINTEST_H
