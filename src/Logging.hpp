#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <iostream>
#include <string>

class Logging {
    public:
        enum TypeMessage {CRITICAL, TRACE, DEBUG};
        static void log(TypeMessage type_message, std::string message);
};

#endif // LOGGING_HPP
