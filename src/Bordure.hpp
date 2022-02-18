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
    Type_noeud type_noeud;

    public:
    // CONSTRUCTEURS
    Bordure(Type_noeud type_noeud);

    // DESTRUCTEUR
    ~Bordure();

    // METHODES
};

#endif