#ifndef RANDOMSKEWNESSTEST_H
#define RANDOMSKEWNESSTEST_H

#include <Test.h>
#include "random/Random.h"
#include "RandomTestHelper.h"



#include <iostream>

class RandomSkewnessTest : public test::Test {
public:

	RandomSkewnessTest() : Test("RandomSkewnessTest") {}

	test::TestResult test() {
		Random random(2);
		std::vector<double> data = RandomTestHelper::generate(random, N);
		auto mu3 = RandomTestHelper::moment(data, 3);
		auto sigma = std::sqrt(RandomTestHelper::moment(data, 2));
		const double result = mu3 / std::pow(sigma, 3);
		
		
		std::cout << "skewness: " << result << std::endl;
		return fail("Test is not implemented");
	}

private:
	static const uint N = 1e6;
};


#endif //RANDOMSKEWNESSTEST_H
