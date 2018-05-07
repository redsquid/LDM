#include "PotentialTest.h"

#include "potential/Potential.h"
#include "potential/Shape.h"

#include <iostream>
#include <chrono>

PotentialTest::PotentialTest() :
Test("PotentialTest")
{
}

PotentialTest::~PotentialTest() {

}

test::TestResult PotentialTest::test() {


    auto begin = std::chrono::high_resolution_clock::now();

    Potential potential(252, 100);

    double vL = 6;
    double vK = 3;

    for (double q1 = 0.5; q1 < 4.5; q1 += 0.05) {
        Shape shape(q1, 0.2, -0.5);
        potential(shape, vL, vK);
        //std::cout << q1 << " " << potential(shape, vL, vK) << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();


    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << std::endl;

    return fail("Test is not implemented");
}
