// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include <iostream>

#include "Noeud.hpp"
#include "Meeple.hpp"
#include "Joueur.hpp"

/**
 * Classe Element
 *
 * Hérite de la classe Noeud et permet de représenter les emplacements ou l'on pose un Pion.
 * */
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
