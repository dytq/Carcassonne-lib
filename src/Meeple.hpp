// DIRECTIVES
#ifndef MEEPLE_HPP
#define MEEPLE_HPP

// LIBRAIRIES
#include "Joueur.hpp"
#include "Element.hpp"

class Joueur;

// CLASSE
class Meeple
{
    private:
    // VARIABLES
    Joueur * joueur;
    Element * element;

    public:
    // CONSTRUCTEURS
    Meeple(Joueur * joueur);

    // DESTRUCTEUR
    ~Meeple();

    // METHODES
};

#endif