// DIRECTIVES
#ifndef LOGGING_HPP
#define LOGGING_HPP

// LIBRAIRIES
#include <iostream>
#include <string>

// CLASSE
class Logging
{
    public:
        enum TypeMessage {CRITICAL, TRACE, DEBUG};
        static void log(TypeMessage type_message, std::string message);
};

#endif