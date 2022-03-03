// DIRECTIVES
#ifndef PION_HPP
#define PION_HPP

// LIBRAIRIES
#include <list>

#include "Meeple.hpp"
#include "Tuile.hpp"
#include "Chevalier.hpp"
#include "Brigand.hpp"
#include "Moine.hpp"
#include "Joueur.hpp"
#include "Paysan.hpp"
#include "Element.hpp"
#include "Noeud.hpp"
#include "Logging.hpp"

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
        static Meeple * generate_meeple(Joueur * joueur, Element * element, Tuile * tuile);
        void ajouter_meeple(Meeple * meeple);
        void supprimer_meeple(Meeple * meeple);
        const std::list<Meeple *> get_stack_meeple();
};

#endif