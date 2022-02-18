// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include "Noeud.hpp"

class Meaple;

// CLASSE
class Element : Noeud
{
    private:
    // VARIABLES
    Meaple * meaple;

    public:
    // CONSTRUCTEURS
    Element(Type_noeud type_noeud);

    // DESTRUCTEUR
    ~Element();

    // METHODES
    Meaple * recuperer_meaple();
    void ajouter_meaple();
    void supprimer_meaple();
};

#endif