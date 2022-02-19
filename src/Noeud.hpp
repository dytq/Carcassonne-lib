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
        static enum type_element{ROUTE, VILLE, ABBAYE, PLAINE} element_enum;
        std::list<Noeud> noeuds_voisins;

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
