#include "Test.h"

namespace test {


Test::Test(const std::string _name) :
    name(_name)
{
}

Test::~Test() {

}

TestResult Test::fail(std::string message) const {
    return TestResult(name, message, false);
}

TestResult Test::success() const {
    return TestResult(name, true);
}

}
