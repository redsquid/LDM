#ifndef ROTATIONENERGYTEST_H
#define ROTATIONENERGYTEST_H

#include "utils/test/Test.h"

class RotationEnergyTest : public test::Test {
public:
    RotationEnergyTest();
    virtual ~RotationEnergyTest();
    test::TestResult test() override;
};

#endif // ROTATIONENERGYTEST_H
