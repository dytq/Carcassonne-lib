#ifndef MEEPLE_H
#define MEEPLE_H

#include "Joueur.hpp"
#include "Element.hpp"

class Joueur;

class Meeple {
    private:
        Joueur * joueur;
        Element * element;
};

#endif // MEEPLE_H
