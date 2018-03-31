#ifndef POTENTIALMAINTEST_H
#define POTENTIALMAINTEST_H

#include "utils/test/TestSuite.h"
#include "test/CoulumbEnergyTest.h"
#include "test/SurfaceEnergyTest.h"
#include "test/RotationEnergyTest.h"
#include "test/PotentialTest.h"

class PotentialMainTest {
public:
    PotentialMainTest() = delete;

    static void doTest() {
        test::TestSuite suite;
        suite.registerTest(new SurfaceEnergyTest());
        suite.registerTest(new CoulumbEnergyTest());
        suite.registerTest(new RotationEnergyTest());
        suite.registerTest(new PotentialTest());
        suite.runTests();
    }

};

#endif // POTENTIALMAINTEST_H
