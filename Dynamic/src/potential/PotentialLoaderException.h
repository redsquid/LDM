#ifndef POTENTIALLOADEREXCEPTION_H
#define POTENTIALLOADEREXCEPTION_H

#include "core/exception/Exception.h"

class PotentialLoaderException : public Exception {
public:
	PotentialLoaderException(std::string message) : Exception(message) {
	}
};

#endif //POTENTIALLOADEREXCEPTION_H

