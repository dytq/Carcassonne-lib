// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <list>

// CLASSE
class Noeud
{
    public:
    // VARIABLES
        static enum type_element{ROUTE, VILLE, ABBAYE, PLAINE} element_enum;

    protected:
        std::list<Noeud> noeuds_voisins;
        type_element element;

        // CONSTRUCTEURS
        Noeud();
    public:
        // DESTRUCTEUR
        ~Noeud();

        // METHODES
        void add_link(Noeud noeud);
        std::list<Noeud> get_noeud_voisins();
        void set_link(Noeud * noeud);
        Noeud::type_element get_type_element();
};

#endif