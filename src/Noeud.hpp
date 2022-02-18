// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <list>

// CLASSE
class Noeud
{
    protected:
    // VARIABLES
    static enum Type_noeud{Plaine, Route, Ville, Abbaye} Type_noeud_enum;
    std::list<Noeud> noeud_voisin;

    public:
    // CONSTRUCTEURS
    Noeud();

    // DESTRUCTEUR
    ~Noeud();

    // METHODES
    std::list<Noeud> noeud_voisins();
    void add_voisin(Noeud * noeud);
};

#endif