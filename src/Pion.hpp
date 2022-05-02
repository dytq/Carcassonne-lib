// DIRECTIVES
#ifndef PION_HPP
#define PION_HPP

// LIBRAIRIES
#include <array>

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
        std::array<Meeple *,7> stackMeeple;

    public:
        // CONSTRUCTEURS
        Pion();

        // DESTRUCTEUR
        ~Pion();

        // METHODES STATIC
        static Meeple * generate_meeple(Joueur * joueur, Element * element, const std::array<std::array<Tuile*, 144>, 144> * etat_du_jeu, std::pair<int, int> position_tuile);
        static int estimer_element_points(Joueur * joueur, Element * element, int status_du_jeu, const std::array<std::array<Tuile *, 144>, 144> *etat_du_jeu, std::pair<int, int> position_tuile);

        // METHODES OBJETS PION
        void ajouter_meeple(Meeple * meeple, int indice);
        void supprimer_meeple(Meeple * meeple);
        const std::array<Meeple *,7> get_stack_meeple();
        bool si_pion_non_place();
        int get_nbr_meeple();
        int get_indice(Meeple * meeple);
        int get_premier_indice_libre();
};

#endif
