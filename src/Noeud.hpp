// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <list>

/**
 * Classe Noeud
 *
 * Permet de faire l'interface pour le pacours de la couche 'noeud'.
 * La couche 'noeud' est un réseau constitué d'élément de bordure indistinguable lors de parcours du réseau.
 * Un noeuds peut être de plusieurs type, comme une route, une ville, une plaine ou bien une abbaye.
 * */
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
