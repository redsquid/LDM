#ifndef ROTATIONENERGYSHARPTEST_H
#define ROTATIONENERGYSHARPTEST_H

#include "utils/test/Test.h"
#include "potential/RotationEnergySharp.h"

class RotationEnergySharpTest : public test::Test {
public:
    RotationEnergySharpTest();
    virtual ~RotationEnergySharpTest();
    test::TestResult test() override;

private:
    bool doTest(double c, double expected) const;
    static constexpr double EPS = 1e-3;
    static constexpr uint A = 252;
    static constexpr int L = 6;
    static constexpr int K = 3;
    const RotationEnergySharp re;
};

#endif // ROTATIONENERGYSHARPTEST_H
