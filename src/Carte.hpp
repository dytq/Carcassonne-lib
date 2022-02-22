// DIRECTIVES
#ifndef CARTE_HPP
#define CARTE_HPP

// LIBRAIRIES
#include <array>
#include <list>
#include <vector>

#include "Bordure.hpp"
#include "Element.hpp"

// CLASSE
class Carte
{
    private:
        // VARIABLES
        std::array<Carte*,4> carteVoisines;
        std::list<Bordure *> bordure;
        std::vector<Element *> element;

    public:
        // CONSTRUCTEURS
        Carte();

        // DESTRUCTEUR
        ~Carte();

        // METHODES
        std::vector<Element *> get_element(Carte * carte);
        bool est_vide();
};

#endif