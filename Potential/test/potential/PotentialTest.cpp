#include "PotentialTest.h"

#include "potential/Potential.h"
#include "potential/Shape.h"

#include <iostream>

PotentialTest::PotentialTest() :
Test("PotentialTest")
{
}

PotentialTest::~PotentialTest() {

}

test::TestResult PotentialTest::test() {

    Potential potential(252, 100);

    double vL = 6;
    double vK = 3;


//   Shape shape(1, 0., 0.);

//    double result = potential(shape, vI, vK);

//    std::cout << "Result: " << result << std::endl;
//    std::cout << "-------------------" << std::endl;


//   int N = 100;
//   double c = 1.0;
//   double cmin = -c;
//   double cmax = c;
//   double dz = (cmax - cmin) / N;
//   double z = -c;
//   Shape shape(c, 0., 0.);
//   double dsh = 0;
//    for(int i = 0; i < N; i++) {
//        dsh = (shape(z + dz) - shape(z - dz)) / (2 * dz);
//        std::cout << z << " " << dsh << " " << shape.deriv(z) << std::endl;
//        z += dz;
//    }


    for (double q1 = 0.5; q1 < 4.5; q1 += 0.05) {
        Shape shape(q1, 0.2, -0.5);
        std::cout << q1 << " " << potential(shape, vL, vK) << std::endl;

    }

//    Shape s0(1.9, 0., 0.);
//    for (double z = -2.5; z <= 2.5; z += 0.05) {
//        std::cout << z << " " << s0(z) << std::endl;
//    }

    return fail("Test is not implemented");
}
