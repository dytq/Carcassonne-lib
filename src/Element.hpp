// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include <iostream>

#include "Noeud.hpp"
#include "Meeple.hpp"
#include "Joueur.hpp"
//#include "Chevalier.hpp"
//#include "Brigand.hpp"
//#include "Moine.hpp"

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
        void supprimer_meeple();
        void set_point(int point, int i);
        void ajouter_meeple(Meeple * meeple);
};

#endif
