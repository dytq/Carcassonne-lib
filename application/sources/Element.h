#ifndef ELEMENT_H
#define ELEMENT_H

#include "Noeud.h"

class Meaple;

class Element : Noeud {
    private:
        Meaple * meaple;
    public:
        Element(Type_noeud type_noeud);
        Meaple * recuperer_meaple();
        void ajouter_meaple();
        void supprimer_meaple();
        ~Element() {}
};

#endif // ELEMENT_H
