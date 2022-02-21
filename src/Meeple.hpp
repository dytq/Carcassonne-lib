#ifndef MEEPLE_H
#define MEEPLE_H

#include <map>
#include <list>

#include "Joueur.hpp"
#include "Noeud.hpp"

class Meeple {
    private:
        Joueur * joueur;
        Noeud * noeuds;
    public:
        Meeple();
        virtual int compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple*>> mapJoueurListeMeeple, int * score) { return 0;}
        //virtual Noeud * get_noeud();
};

#endif // MEEPLE_H
