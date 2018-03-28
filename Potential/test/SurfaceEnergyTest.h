#ifndef SURFACEENERGYTEST_H
#define SURFACEENERGYTEST_H

#include "utils/test/Test.h"

class SurfaceEnergyTest : public test::Test {
public:
    SurfaceEnergyTest();
    virtual ~SurfaceEnergyTest();
    test::TestResult test() override;
};

#endif // SURFACEENERGYTEST_H
