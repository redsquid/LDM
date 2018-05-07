#ifndef FREEENERGYTEST_H
#define FREEENERGYTEST_H

#include "utils/test/Test.h"
#include "potential/FreeEnergy.h"

class FreeEnergyTest : public test::Test {
public:
    FreeEnergyTest();
    virtual ~FreeEnergyTest();
    test::TestResult test() override;

};

#endif // FREEENERGYTEST_H
