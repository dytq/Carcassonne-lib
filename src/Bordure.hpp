// DIRECTIVES
#ifndef BORDURE_HPP
#define BORDURE_HPP

// LIBRAIRIES
#include <array>

#include "Noeud.hpp"

/**
 * Classe Bordure
 *
 * Hérite de la classe Noeud. Elle représente physiquement les bordures de la carte et sert de porte de sortie lors du parcours du réseau de la couche 'noeud'
 * Elle contient des bordures fils permettant de proposer 3 interfaces d'entrées/sorties vers la carte voisines (par exemple dans le cas ou on a une route qui sépare deux plaines, pour le parcours de graphe on a donc 3 chemins distincts)
 **/
class Bordure : Noeud
{
    private:
        // VARIABLES
        Noeud::type_element type_noeud;
        std::array<Bordure *,3> bordureFils;

    public:
        // CONSTRUCTEURS
        Bordure(Noeud::type_element type_noeud);

        // DESTRUCTEUR
        ~Bordure();

        // METHODES
        std::array<Bordure *,3> get_bordure_fils();
        void set_bordure_fils(std::array<Bordure*,3> bordureFils);
};

#endif
