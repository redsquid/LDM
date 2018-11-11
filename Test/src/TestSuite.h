#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "ITest.h"
#include <set>

namespace test {


class TestSuite {
public:
    TestSuite();
    virtual ~TestSuite();
    void registerTest(ITest* test);
    void runTests();

private:
    std::set<ITest*> tests;
};

}

#endif // TESTSUITE_H
