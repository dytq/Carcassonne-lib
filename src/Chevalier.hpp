// DIRECTIVES
#ifndef CHEVALIER_HPP
#define CHEVALIER_HPP

// LIBRAIRIES
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Element.hpp"

/**
 * @title: Meeple de type chevalier
 *
 * @description: Cette classe définit un chevalier. Un chevalier est posé sur une ville ou bien un ville blason. Pour compter le nombre de points que peut rapporter un chevalier on regarde si la ville est entouré de forteresse.
 * */
class Chevalier : public Meeple
{
    public:
        // CONSTRUCTEURS
        Chevalier(Joueur * joueur, Noeud * noeud);
        
        // DESTRUCTEUR
        ~Chevalier();

        // METHODES
        bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score) override;
};

#endif
