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
 * Permet de représenté une liste de pions.
 **/
class Pion
{
    private:
        // VARIABLES
        std::list<Meeple *> stackMeeple;
        int nbr_meeple_max;

    public:
        // CONSTRUCTEURS
        Pion(int nbr_pions);

        // DESTRUCTEUR
        ~Pion();

        // METHODES STATIC
        static Meeple * generate_meeple(Joueur * joueur, Element * element, Tuile * tuile);
        static int estimer_meeple_points(Meeple * meeple, int status_du_jeu);

        // METHODES OBJETS PION
        void ajouter_meeple(Meeple * meeple);
        void supprimer_meeple(Meeple * meeple);
        const std::list<Meeple *> get_stack_meeple();
        bool si_pion_non_place();
};

#endif
