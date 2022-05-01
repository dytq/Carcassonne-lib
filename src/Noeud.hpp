// DIRECTIVES
#ifndef NOEUD_HPP
#define NOEUD_HPP

// LIBRAIRIES
#include <vector>
#include <algorithm>

#include "Logging.hpp"

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
        static enum type_element{VOID, ROUTE, VILLE, VILLE_BLASON, ABBAYE, PLAINE} element_enum;

    protected:
        std::vector<Noeud *> noeuds_voisins;
        type_element element;
        int point_en_cours;
        int point_final;
        Noeud();

    public:
         // CONSTRUCTEURS
        // DESTRUCTEUR
        ~Noeud();

        // METHODES
        void set_lien(Noeud * noeud);   // ajoute un lien simple
        void set_voisin(Noeud * noeud); // ajoute un lien voisin
        Noeud * get_voisin(int index);  // retourne le voisin front
        virtual int get_points(int status_du_jeu);
        virtual void supprimer_meeple();
        void remove_tuile_voisin(Noeud * noeud); // supprime en fonction de l'addresse du noeuds donné en param
        bool static compare_type_element(Noeud::type_element type_element1, Noeud::type_element type_element2); // compare deux types éléments sans prendre en compte des options (ville est égale à ville_blason)
        bool has_nullptr();
        int get_nbr_voisins();
        Noeud::type_element get_type_element();
        void set_type_element(Noeud::type_element type);
        Noeud * noeud_fils(Noeud * noeud_pere, int indexe);
};

#endif
