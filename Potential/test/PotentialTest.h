#ifndef POTENTIALTEST_H
#define POTENTIALTEST_H

#include "utils/test/TestSuite.h"
#include "test/CoulumbEnergyTest.h"
#include "test/SurfaceEnergyTest.h"
#include "test/RotationEnergyTest.h"

class PotentialTest {
public:
    PotentialTest() = delete;

    static void doTest() {
        test::TestSuite suite;
        suite.registerTest(new SurfaceEnergyTest());
        suite.registerTest(new CoulumbEnergyTest());
        suite.registerTest(new RotationEnergyTest());
        suite.runTests();
    }

};

#endif // POTENTIALTEST_H
