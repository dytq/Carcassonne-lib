#include "Humain.hpp"

Humain::Humain()
{
    Joueur::score = 0;
}

int Humain::choix_de_emplacement_libre()
{
    int indice_emplacement_libre = 0;
    std::cin >> indice_emplacement_libre;
    
    return indice_emplacement_libre;
}

bool Humain::choix_si_poser_meeple()
{
    std::string poser_pion;
    std::cin >> poser_pion;
    if(!poser_pion.compare("oui"))
    {
        return true;
    }
    else
    {
        if(!poser_pion.compare("non"))
        {
            return false;
        }
    }
    Logging::log(Logging::DEBUG, "Choix de Humain non définie retourne non");
    return false;
}

int Humain::choix_de_element_libre()
{
    int indice_element = 0;
    std::cin >> indice_element;
    
    return indice_element;
}
