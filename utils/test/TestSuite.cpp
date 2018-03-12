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

        std::cout << result.getName() << ":\t";
        std::string str = result.isSuccess() ? "OK" : std::string("ERROR:\n\t") + result.getMessage();
        std::cout << str << std::endl;
    }

}

}
