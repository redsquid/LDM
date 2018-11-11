#ifndef POTENTIALLOADER_H
#define POTENTIALLOADER_H

#include "potential/Potential.h"

class PotentialLoader {
public:
	PotentialLoader();
	virtual ~PotentialLoader();

	Potential load();
};

#endif //POTENTIALLOADER_H

