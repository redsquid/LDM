#ifndef ROTATIONENERGYSHARPTEST_H
#define ROTATIONENERGYSHARPTEST_H

#include "utils/test/Test.h"

class RotationEnergySharpTest : public test::Test {
public:
    RotationEnergySharpTest();
    virtual ~RotationEnergySharpTest();
    test::TestResult test() override;
};

#endif // ROTATIONENERGYSHARPTEST_H
