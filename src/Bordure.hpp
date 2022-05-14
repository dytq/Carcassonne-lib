// DIRECTIVES
#ifndef BORDURE_HPP
#define BORDURE_HPP

// LIBRAIRIES
#include <array>

#include "Noeud.hpp"

/**
 * @title: Bordure d'une tuile
 *
 * @description: Hérite de la classe Noeud. Elle représente physiquement les bordures de la tuile et sert de porte de sortie lors du parcours du réseau de la couche 'noeud'. 
 * Elle contient des bordures fils permettant de proposer 3 interfaces d'entrées/sorties vers la tuiles voisines (par exemple dans le cas ou on a une route qui sépare deux plaines, pour le parcours de graphe on a donc 3 chemins distincts qui peuvent diverger).
 **/
class Bordure : public Noeud
{
    private:
        // VARIABLES
        std::array<Bordure *, 3> bordureFils;

    public:
        // CONSTRUCTEURS
        Bordure() {};

        // DESTRUCTEUR
        ~Bordure();

        // METHODES
        Bordure * get_bordure_fils(int indice);
        void set_bordure_fils(int indice, Noeud::type_element element);
        int get_points(int status_du_jeu);
        void set_type_element(Noeud::type_element type_noeud);
};

#endif
