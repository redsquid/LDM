#ifndef ROTATIONENERGYTEST_H
#define ROTATIONENERGYTEST_H

#include "utils/test/Test.h"
#include "potential/RotationEnergy.h"

class RotationEnergyTest : public test::Test {
public:
    RotationEnergyTest();
    virtual ~RotationEnergyTest();
    test::TestResult test() override;

private:
    bool doTest(const double q1, const double q2, const double q3, const double expected) const;
    static constexpr double EPS = 1e-1;
    static constexpr uint A = 252;
    static constexpr uint Z = 100;
    static constexpr int L = 6;
    static constexpr int K = 3;
    const RotationEnergy re;

};

#endif // ROTATIONENERGYTEST_H
