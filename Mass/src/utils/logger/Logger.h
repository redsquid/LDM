#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

namespace logger {

class Logger {
public:
    Logger(const std::string className);

    void debug(const std::string function, const std::string message);
    void info(const std::string function, const std::string message);
    template<typename T> void print(const T message) const {
        std::cout << message << std::endl;
    }
private:
    static const std::string DEBUG;
    static const std::string INFO;
    const std::string className;
};

}

#endif // LOGGER_H
