#ifndef SURFACEENERGYTEST_H
#define SURFACEENERGYTEST_H

#include "utils/test/Test.h"
#include "potential/SurfaceEnergy.h"

class SurfaceEnergyTest : public test::Test {
public:
    SurfaceEnergyTest();
    virtual ~SurfaceEnergyTest();
    test::TestResult test() override;

private:
    bool doTest(const double q1, const double q2, const double q3, const double expected) const;
    static constexpr double EPS = 1e-1;
    static constexpr uint Z = 100;
    static constexpr uint A = 252;
    const SurfaceEnergy se;
};

#endif // SURFACEENERGYTEST_H
