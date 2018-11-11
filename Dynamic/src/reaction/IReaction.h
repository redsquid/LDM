#ifndef IREACTION_H
#define IREACTION_H

#include <cstdlib>
#include "Result.h"


class IReaction {
public:
	virtual ~IReaction() {}

	virtual Result compute() = 0;
};

#endif //IREACTION_H
