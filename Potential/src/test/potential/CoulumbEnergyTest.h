#ifndef COULUMBENERGYTEST_H
#define COULUMBENERGYTEST_H

#include "utils/test/Test.h"
#include "potential/CoulombEnergy.h"

class CoulumbEnergyTest : public test::Test {
public:
    CoulumbEnergyTest();
    virtual ~CoulumbEnergyTest();
    test::TestResult test() override;

private:
    bool doTest(const double q1, const double q2, const double q3, const double expected) const;
    static constexpr double EPS = 1e-1;
    static constexpr uint Z = 100;
    static constexpr uint A = 252;
    const CoulombEnergy ce;
};

#endif // COULUMBENERGYTEST_H
