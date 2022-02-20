#ifndef MEEPLE_H
#define MEEPLE_H

#include <vector>

//#include "Joueur.hpp"
#include "Noeud.hpp"

class Meeple {
    public:
        static enum type_comptage{ COMPLET, IMCOMPLET} type_comptage_enum;
        virtual int compter_points(type_comptage comptage, std::vector<Meeple*> listMeeple, int * score) { return 0;}
        //virtual Noeud * get_noeud();
};

#endif // MEEPLE_H
