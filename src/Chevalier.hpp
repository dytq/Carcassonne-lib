#ifndef CHEVALIER_H
#define CHEVALIER_H

#include "Meeple.hpp"
#include "Joueur.hpp"

class Chevalier : public Meeple {
    public:
        Chevalier(Joueur * joueur, Noeud * noeud);
        int compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score);
};

#endif //CHEVALIER_H
