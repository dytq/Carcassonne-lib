// LIBRAIRIES
#include "Logging.hpp"


// FONCTIONS
/**
 * Permet la journalisation d'un message.
 *
 * @param type message le type de message
 * @param message la chaine de caractère du message
 * */
void Logging::log(TypeMessage type_message, char * message)
{
    switch (type_message) {

        case CRITICAL:
            #ifdef CRITICAL_MSG
            std::cout << "MESSAGE CRITIQUE: " << message << std::endl;
            #endif // CRITICAL_MSG
            break;

        case DEBUG:
            #ifdef DEBUG_MSG
            std::cout << "MESSAGE DEBUG: " << message << std::endl;
            #endif // DEBUG_MSG
            break;

        case TRACE:
            #ifdef TRACE_MSG
            std::cout << "MESSAGE TRACE: " << message << std::endl;
            #endif // TRACE_MSG
            break;

        default:
            Logging::log(Logging::DEBUG, "type du message donnée au logger non valide");
            break;
    }
}

/**
 * Permet la journalisation d'un message.
 *
 * @param type message le type de message
 * @param format permet d'afficher un messages avec une liste d'argument
 * */
void Logging::log(TypeMessage type_message, const char * format, ...)
{
    char sBuffer[1024];
    va_list args;

    va_start(args, format);

    std::vsprintf(sBuffer, format, args);
    Logging::log(type_message, sBuffer);
}
