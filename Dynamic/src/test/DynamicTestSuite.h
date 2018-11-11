#ifndef DYNAMICTESTSUITE_H
#define DYNAMICTESTSUITE_H

#include <TestSuite.h>
#include "test/random/RandomMeanTest.h"
#include "test/random/RandomVarianceTest.h"
#include "test/random/RandomKurtosisTest.h"
#include "test/random/RandomSkewnessTest.h"

class DynamicTestSuite {
public:
	DynamicTestSuite() = delete;

	static void doTest() {
		test::TestSuite suite;
		suite.registerTest(new RandomMeanTest());
		suite.registerTest(new RandomVarianceTest());
		suite.registerTest(new RandomKurtosisTest());
		suite.registerTest(new RandomSkewnessTest());

		suite.runTests();
	}

};


#endif //DYNAMICTESTSUITE_H


