#ifndef REACTION_H
#define REACTION_H

#include <cstdlib>
#include "nucleus/Nucleus.h"
#include "IReaction.h"
#include "random/Random.h"

class Reaction : public IReaction {
public:
	Reaction(const Nucleus& projectile, const Nucleus& target);
	virtual ~Reaction();
	
	Result compute();

private:

	static constexpr double DEV = 2.;

	Random rnd;


};

#endif //REACTION_H
