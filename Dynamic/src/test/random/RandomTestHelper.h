#ifndef RANDOMTESTHELPER_H
#define RANDOMTESTHELPER_H

#include "random/IRandom.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class RandomTestHelper {
public:
	RandomTestHelper() = delete;

	static vector<double> generate(IRandom& random, const uint n) {
		vector<double> data(n);
		std::generate(data.begin(), data.end(), [&random]() {return random.next();});
		return data;
	}

	static double mean(const vector<double>& data) {
		return accumulate(data.begin(), data.end(), 0.) / data.size();
	}

	static double moment(const vector<double>& data, double ord) {
		auto m = mean(data);
		vector<double> temp(data.size());
		transform(data.begin(), data.end(), temp.begin(), [m, ord](double x) {return pow(x - m, ord);});
		return  mean(temp);
	}
};

#endif //RANDOMTESTHELPER_H
