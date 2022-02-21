#ifndef BRIGAND_H
#define BRIGAND_H

#include "Meeple.hpp"
#include "Joueur.hpp"

class Brigand : public Meeple {
    public:
        Brigand(Joueur * joueur, Noeud * noeud);
        int compter_points(int status_du_jeu, std::map<Joueur*, std::list<Meeple*>>, int * score);
};

#endif // BRIGAND_H
