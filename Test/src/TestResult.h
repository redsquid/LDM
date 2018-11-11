#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <string>

namespace test {


class TestResult {
public:
    TestResult(std::string testName, bool isSucces);
    TestResult(std::string testName, std::string message, bool isSucces);

    std::string getName() const;
    std::string getMessage() const;
    bool isSuccess() const;

private:
    const std::string name;
    const std::string message;
    const bool success;
};

}

#endif // TESTRESULT_H
