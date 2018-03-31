#ifndef SURFACEENERGYSHARPTEST_H
#define SURFACEENERGYSHARPTEST_H

#include "utils/test/Test.h"

class SurfaceEnergySharpTest : public test::Test {
public:
    SurfaceEnergySharpTest();
    virtual ~SurfaceEnergySharpTest();
    test::TestResult test() override;
};

#endif // SURFACEENERGYSHARPTEST_H
