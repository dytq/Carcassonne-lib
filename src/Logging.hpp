// DIRECTIVES
#ifndef LOGGING_HPP
#define LOGGING_HPP

// LIBRAIRIES
#include <iostream>
#include <string>

#include <stdarg.h>  // args
#include <stdio.h>



// CLASSE
class Logging
{
    public:
        enum TypeMessage {CRITICAL, TRACE, DEBUG};
        static void log(TypeMessage type_message, char * message);
        static void log(TypeMessage type_message, const char * format, ...);
};

#endif
