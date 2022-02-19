// DIRECTIVES
#ifndef BORDURE_HPP
#define BORDURE_HPP

// LIBRAIRIES
#include "Noeud.hpp"

// CLASSE
class Bordure : Noeud
{
    private:
    // VARIABLES
    Noeud::type_element type_noeud;

    public:
    // CONSTRUCTEURS
    Bordure(Noeud::type_element type_noeud);

    // DESTRUCTEUR
    ~Bordure();

    // METHODES
};

#endif
