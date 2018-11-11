#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class Logger {
public:

	template<typename T> static void print(T message) {
		std::cout << message << std::flush;
	}

	static void ok() {
		std::cout << " [OK] " << std::endl;
	}

	static void error(std::string message) {
		std::cout << " [ERROR] Couse: " << message << std::endl;
	}

};


#endif //LOGGER_H

