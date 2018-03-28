#ifndef ITEST_H
#define ITEST_H

#include "TestResult.h"

namespace test {


class ITest {
public:
    virtual ~ITest() {}
    virtual TestResult test() = 0;
};

}

#endif // ITEST_H
