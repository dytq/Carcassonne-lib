// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include "Noeud.hpp"
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Constantes.hpp"

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
        int get_points(int status_du_jeu);
};

#endif
