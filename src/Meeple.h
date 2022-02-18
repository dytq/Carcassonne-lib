#ifndef MEEPLE_H
#define MEEPLE_H

#include "Joueur.h"
#include "Element.h"

class Joueur;

class Meeple {
    private:
        Joueur * joueur;
        Element * element;
};

#endif // MEEPLE_H
