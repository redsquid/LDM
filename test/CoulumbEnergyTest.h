#ifndef COULUMBENERGYTEST_H
#define COULUMBENERGYTEST_H

#include "utils/test/Test.h"

class CoulumbEnergyTest : public test::Test {
public:
    CoulumbEnergyTest();
    virtual ~CoulumbEnergyTest();
    test::TestResult test() override;
};

#endif // COULUMBENERGYTEST_H
