#include "Test.h"

namespace test {


Test::Test(const std::string _name) :
    name(_name)
{
}

Test::~Test() {

}

TestResult Test::fail(std::string message) {
    return TestResult(name, message, false);
}

TestResult Test::success() {
    return TestResult(name, true);
}

}
