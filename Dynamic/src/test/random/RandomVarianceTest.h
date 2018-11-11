#ifndef RANDOMVARIANCETEST_H
#define RANDOMVARIANCETEST_H

#include <Test.h>
#include "random/Random.h"
#include "test/random/RandomTestHelper.h"


#include <iostream>

using namespace std;

class RandomVarianceTest : public test::Test {
public:
	RandomVarianceTest() : Test("RandomVarianceTest") {}

	test::TestResult test() {
		Random random(2);
		vector<double> data = RandomTestHelper::generate(random, N);
		auto variance = RandomTestHelper::moment(data, 2);
		
		
		std::cout << "vareance: " << variance << std::endl;
		return fail("Test is not implemented");
	}

private:
	static const uint N = 1e6;

};

#endif //RANDOMVARIANCETEST_H
