#ifndef SURFACEENERGYSHARPTEST_H
#define SURFACEENERGYSHARPTEST_H

#include "utils/test/Test.h"
#include "potential/SurfaceEnergySharp.h"

class SurfaceEnergySharpTest : public test::Test {
public:
    SurfaceEnergySharpTest();
    virtual ~SurfaceEnergySharpTest();
    test::TestResult test() override;

private:
    bool doTest(double c, double expected);
    static constexpr double EPS = 1e-1;
    static constexpr uint Z = 100;
    static constexpr uint A = 252;
    const SurfaceEnergySharp se;
};

#endif // SURFACEENERGYSHARPTEST_H
