#include "TestResult.h"

namespace test {


TestResult::TestResult(std::string _testName, bool _isSucces) : TestResult (_testName, "", _isSucces){

}

TestResult::TestResult(std::string _testName, std::string _message, bool _isSucces) :
    name(_testName),
    message(_message),
    success(_isSucces)
{
}

std::string TestResult::getName() const {
    return name;
}

std::string TestResult::getMessage() const {
    return message;
}

bool TestResult::isSuccess() const {
    return success;
}

}
