// DIRECTIVES
#ifndef MEEPLE_HPP
#define MEEPLE_HPP

// LIBRAIRIES
#include <map>
#include <list>

#include "Joueur.hpp"
#include "Noeud.hpp"
#include "Logging.hpp"

/**
 * Classe Meeple
 *
 * Représente un meeple posé dans un noeud
 **/
class Meeple
{
    protected:
        // VARIABLES
        Joueur * joueur;
        Noeud * noeud;

    public:
        // METHODES
        virtual bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple*>> * mapJoueurListeMeeple, int * score);
        Noeud * get_noeud();
        Joueur * get_joueur();
};

#endif
