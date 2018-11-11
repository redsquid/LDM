#ifndef RANDOMKURTOSISTEST_H
#define RANDOMKURTOSISTEST_H

#include <Test.h>
#include "random/Random.h"
#include "RandomTestHelper.h"


#include <iostream>

class RandomKurtosisTest : public test::Test {
public:

	RandomKurtosisTest() : Test("RandomKurtosisTest") {}

	test::TestResult test() {
		Random random(4);
		std::vector<double> data = RandomTestHelper::generate(random, N);
		auto mu4 = RandomTestHelper::moment(data, 4);
		auto sigma = std::sqrt(RandomTestHelper::moment(data, 2));
		const double result = mu4 / std::pow(sigma, 4) - 3;
		
		
		std::cout << "kurtosis: " << result << std::endl; 
		return fail("Test is not implemented");
	}

private:
	static const uint N = 1e6;
};


#endif //RANDOMKURTOSISTEST_H
