// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <list>

// CLASSE
class Noeud
{
    public:
        static enum type_element{ROUTE, VILLE, ABBAYE, PLAINE} element_enum;

    protected:
        // VARIABLES
        std::list<Noeud> noeuds_voisins;
        type_element element;

        // CONSTRUCTEURS
        Noeud();

        // METHODE
        void add_link(Noeud noeud);
    public:
        // DESTRUCTEUR
        ~Noeud() { };

        // METHODES
        std::list<Noeud> get_noeud_voisins();
        void set_link(Noeud * noeud);
};

#endif
