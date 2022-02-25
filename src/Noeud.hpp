// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <list>
#include <iostream>
#include <algorithm>

/**
 * Classe Noeud
 *
 * Permet de faire l'interface pour le pacours de la couche 'noeud'.
 * La couche 'noeud' est un réseau constitué d'élément de bordure indistingable lors de parcours du réseau.
 * Un noeuds peut être de plusieurs type, comme une route, une ville, une plaine ou bien une abbaye.
 * */
class Noeud
{
    public:
        // VARIABLES
        static enum type_element{ROUTE, VILLE, ABBAYE, PLAINE} element_enum;

    protected:
        std::list<Noeud *> noeuds_voisins;
        type_element element;
        int point_en_cours;
        int point_final;

    public:
         // CONSTRUCTEURS
        Noeud();
        // DESTRUCTEUR
        ~Noeud();

        // METHODES
        void add_link(Noeud noeud);
        //std::vector<Noeud> get_noeud_voisins();
        //Noeud * get_noeud_voisin(int index);
        bool has_nullptr();
        int get_nbr_voisins();
        void set_link(Noeud * noeud);
        Noeud::type_element get_type_element();
        virtual int get_points(int status_du_jeu) { return 0;};
        Noeud * noeud_fils(Noeud * noeud_pere, int indexe);
};

#endif // NOEUD.HPP
