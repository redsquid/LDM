#ifndef VOLUMETEST_H
#define VOLUMETEST_H

#include "utils/test/Test.h"

#include <math.h>

class VolumeTest : public test::Test {
public:
    VolumeTest();
    virtual ~VolumeTest();
    test::TestResult test() override;

private:
    static constexpr double V0 = 4. / 3 * M_PI;
};

#endif // VOLUMETEST_H
