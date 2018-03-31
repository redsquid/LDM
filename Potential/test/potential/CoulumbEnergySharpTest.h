#ifndef COULUMBENERGYSHARPTEST_H
#define COULUMBENERGYSHARPTEST_H

#include "utils/test/Test.h"

class CoulumbEnergySharpTest : public test::Test {
public:
    CoulumbEnergySharpTest();
    virtual ~CoulumbEnergySharpTest();
    test::TestResult test() override;
};

#endif // COULUMBENERGYSHARPTEST_H
