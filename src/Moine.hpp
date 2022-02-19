#ifndef MOINE_H
#define MOINE_H

#include "Meeple.hpp"
#include "Joueur.hpp"

class Moine : Meeple {
    public:
        Moine(Joueur * joueur);
        int compter_points(type_comptage comptage, std::vector<Meeple> listMeeple, int * score);

};

#endif // MOINE_H
