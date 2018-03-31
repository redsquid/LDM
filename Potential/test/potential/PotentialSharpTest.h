#ifndef POTENTIALSHARPTEST_H
#define POTENTIALSHARPTEST_H

#include "utils/test/Test.h"

class PotentialSharpTest : public test::Test {
public:
    PotentialSharpTest();
    virtual ~PotentialSharpTest();
    test::TestResult test() override;
};

#endif // POTENTIALSHARPTEST_H
