// DIRECTIVES
#ifndef MEEPLE_HPP
#define MEEPLE_HPP

// LIBRAIRIES
#include <map>
#include <list>

#include "Joueur.hpp"
#include "Noeud.hpp"

// CLASSE
class Meeple
{
    protected:
        // VARIABLES
        Joueur * joueur;
        Noeud * noeud;

    public:
        // METHODES
        virtual int compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple*>> mapJoueurListeMeeple, int * score);
        //virtual Noeud * get_noeud();
};

#endif