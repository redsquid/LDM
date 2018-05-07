#ifndef TEST_H
#define TEST_H

#include "ITest.h"

namespace test {


class Test : public ITest {
public:
    Test(std::string name);
    virtual ~Test();
protected:

    TestResult fail(std::string message) const;
    TestResult success() const;

private:
    const std::string name;

};

}

#endif // TEST_H
