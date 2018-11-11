#ifndef RANDOMMEANTEST_H
#define RANDOMMEANTEST_H

#include <Test.h>
#include "random/Random.h"
#include "RandomTestHelper.h"



#include <iostream>

class RandomMeanTest : public test::Test {
public:

	RandomMeanTest() : Test("RandomMeanTest") {}

	test::TestResult test() {
		Random random(2., 1);
		std::vector<double> data = RandomTestHelper::generate(random, N);
		auto m = RandomTestHelper::mean(data);
		
		std::cout << "average: " << m << std::endl;
		return fail("Test is not implemented");
	}

private:
	static const uint N = 1e6;
};


#endif //RANDOMMEANTEST_H
