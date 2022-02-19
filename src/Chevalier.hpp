#ifndef CHEVALIER_H
#define CHEVALIER_H

#include "Meeple.hpp"
#include "Joueur.hpp"

class Chevalier : Meeple {
    public:
        Chevalier(Joueur * joueur);
        int compter_points(type_comptage comptage, std::vector<Meeple> listMeeple, int * score);
};

#endif //CHEVALIER_H
