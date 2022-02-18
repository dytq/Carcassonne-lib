#ifndef MOINE_H
#define MOINE_H

#include "Meeple.hpp"

class Moine : Meeple {
    public:
        Moine();
        int compter_points(type_comptage comptage, std::vector<Meeple> listMeeple, int * score);

};

#endif // MOINE_H
