// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include "Noeud.hpp"
#include "Plateau.hpp"
#include "Meeple.hpp"

// CLASSE
class Element : public Noeud
{
    private:
    // VARIABLES
    Meeple * meeple;
    int point_en_cours;
    int point_final;

    public:
    // CONSTRUCTEURS
    Element(Noeud::type_element type_noeud);

    // DESTRUCTEUR
    ~Element();

    // METHODES
    Meeple * recuperer_meeple();
    void ajouter_meeple();
    void supprimer_meeple();

    void set_point(int point, Plateau::status status);
};

#endif
