#ifndef POTENTIALTEST_H
#define POTENTIALTEST_H

#include "utils/test/Test.h"

class PotentialTest : public test::Test {
public:
    PotentialTest();
    virtual ~PotentialTest();
    test::TestResult test() override;
};

#endif // POTENTIALSHARPTEST_H
