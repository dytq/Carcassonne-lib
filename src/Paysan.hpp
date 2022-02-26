#ifndef PAYSAN_HPP
#define PAYSAN_HPP
#include "Meeple.hpp"
#include "Noeud.hpp"

class Paysan : Meeple {
    public:
        Paysan(Joueur * joueur, Noeud * noeud);
        bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int *score) override;
};


#endif // PAYSAN_HPP
