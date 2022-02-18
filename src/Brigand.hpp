#ifndef BRIGAND_H
#define BRIGAND_H

#include "Meeple.hpp"
#include "Joueur.hpp"

class Brigand : Meeple {
    public:
        Brigand(Joueur * joueur);
        int compter_points(type_comptage comptage, std::vector<Meeple> listMeeple, int * score);
};

#endif // BRIGAND_H
