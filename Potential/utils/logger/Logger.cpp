#include "Logger.h"

namespace logger {


const std::string Logger::DEBUG("DEBUG");
const std::string Logger::INFO("INFO");

Logger::Logger(const std::string _className) :
    className(_className)
{
}

void Logger::debug(const std::string function, const std::string message) {
    std::cout << DEBUG << ": " << className << ": " << function << ": " << message << std::endl;
}

void Logger::info(const std::string function, const std::string message) {
    std::cout << INFO << ": " << className << ": " << function << ": " << message << std::endl;
}

}
