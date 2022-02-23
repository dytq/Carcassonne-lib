// DIRECTIVES
#ifndef PION_HPP
#define PION_HPP

// LIBRAIRIES
#include <list>
#include <iostream>

#include "Meeple.hpp"
#include "Carte.hpp"
#include "Chevalier.hpp"
#include "Brigand.hpp"
#include "Moine.hpp"
#include "Joueur.hpp"
#include "Element.hpp"
#include "Noeud.hpp"

/**
 * Classe Pion
 *
 * Permet de représenté une pile de pions (ici une pile de meeple).
 **/
class Pion
{
    private:
        // VARIABLES
        std::list<Meeple *> stackMeeple;

    public:
        // CONSTRUCTEURS
        Pion();

        // DESTRUCTEUR
        ~Pion();

        // METHODES
        static Meeple * generate_meeple(Joueur * joueur, Element * element, Carte * carte);
        void ajouter_meeple(Meeple * meeple);
        void supprimer_meeple(Meeple * meeple);
        const std::list<Meeple *> get_stack_meeple();
};

#endif
