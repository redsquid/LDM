#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
public:
	Exception(std::string message) : message_(message)  {
	}

	std::string message() const {
		return message_;
	}

private:
	const std::string message_;
};

#endif //EXCEPTION_H

