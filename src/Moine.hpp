#ifndef MOINE_H
#define MOINE_H

#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Carte.hpp"

class Moine : public Meeple {
    private:
        Carte * carte;
    public:
        Moine(Joueur * joueur, Noeud * noeud, Carte * carte);
        int compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapListeMeeple, int * score);

};

#endif // MOINE_H
