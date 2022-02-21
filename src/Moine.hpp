#ifndef MOINE_H
#define MOINE_H

#include "Meeple.hpp"
#include "Joueur.hpp"

class Moine : public Meeple {
    private:
        Joueur * joueur;
    public:
        Moine(Joueur * joueur, Noeud * noeud);
        int compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapListeMeeple, int * score);

};

#endif // MOINE_H
