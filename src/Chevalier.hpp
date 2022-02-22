// DIRECTIVES
#ifndef CHEVALIER_HPP
#define CHEVALIER_HPP

// LIBRAIRIES
#include "Meeple.hpp"
#include "Joueur.hpp"

// CLASSE
class Chevalier : public Meeple
{
        // VARIABLES

    public:
        // CONSTRUCTEURS
        Chevalier(Joueur * joueur, Noeud * noeud);
        
        // DESTRUCTEUR
        ~Chevalier();

        // METHODES
        int compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score);
};

#endif