#ifndef COULUMBENERGYSHARPTEST_H
#define COULUMBENERGYSHARPTEST_H

#include "utils/test/Test.h"
#include "potential/CoulombEnergySharp.h"

class CoulumbEnergySharpTest : public test::Test {
public:
    CoulumbEnergySharpTest();
    virtual ~CoulumbEnergySharpTest();
    test::TestResult test() override;

private:
    bool doTest(double c, double expected);
    static constexpr double EPS = 1e-1;
    static constexpr uint Z = 100;
    static constexpr uint A = 252;
    const CoulombEnergySharp ce;
};

#endif // COULUMBENERGYSHARPTEST_H
