#ifndef NOEUD_H
#define NOEUD_H

#include <list>

class Noeud {
    protected:
        Noeud() {}
        std::list<Noeud> noeud_voisin;
    public:
        static enum Type_noeud{Plaine, Route, Ville, Abbaye} Type_noeud_enum;

        std::list<Noeud> noeud_voisins();
        void add_voisin(Noeud * noeud);
        ~Noeud() { }
};

#endif // NOEUD_H
