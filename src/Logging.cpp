// LIBRAIRIES
#include "Logging.hpp"

// FONCTIONS
void Logging::log(TypeMessage type_message, char * message)
{
    switch (type_message) {

        case CRITICAL:
            std::cout << "MESSAGE CRITIQUE: " << message << std::endl;
            break;

        case DEBUG:
            std::cout << "MESSAGE DEBUG: " << message << std::endl;
            break;

        case TRACE:
            std::cout << "MESSAGE TRACE: " << message << std::endl;
            break;

        default:
            Logging::log(Logging::DEBUG, "type du message donnée au logger non valide");
            break;
    }
}

void Logging::log(TypeMessage type_message, const char * format, ...)
{
    char sBuffer[1024];
    va_list args;

    va_start(args, format);

    std::vsprintf(sBuffer, format, args);
    Logging::log(type_message, sBuffer);
}
