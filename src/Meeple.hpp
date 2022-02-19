#ifndef MEEPLE_H
#define MEEPLE_H

#include <vector>

class Element;

class Meeple {
    private:
        Element * element;
    public:
        static enum type_comptage{ COMPLET, IMCOMPLET} type_comptage_enum;
        virtual int compter_points(type_comptage comptage, std::vector<Meeple> listMeeple, int * score) { return 0;}
};

#endif // MEEPLE_H
