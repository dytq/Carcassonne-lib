#ifndef MEAPLE_H
#define MEAPLE_H

#include "Joueur.h"
#include "Element.h"

class Joueur;

class Meaple {

    private:
        Joueur * joueur;
        Element * element;
    public:
        Meaple(Joueur * joueur);
        ~Meaple() {}
};

#endif // MEAPLE_H
