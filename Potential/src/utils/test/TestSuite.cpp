#include "TestSuite.h"

#include <iostream>

namespace test {


TestSuite::TestSuite() {
}

TestSuite::~TestSuite() {
    for (auto test : tests) {
       delete test;
    }
}

void TestSuite::registerTest(ITest* test) {
    tests.insert(test);
}

void TestSuite::runTests() {

    for (auto test : tests) {
        TestResult result = test->test();

        std::string str = result.isSuccess() ? "  OK\t" + result.getName()
                : std::string("  ERROR\t") + result.getName() + "\n" + result.getMessage();

        std::cout << str << std::endl;
    }
}

}
