#include "Logging.hpp"

void Logging::log(TypeMessage type_message, std::string message) {

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
